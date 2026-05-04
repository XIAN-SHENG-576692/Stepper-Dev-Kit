import clang.cindex
import sys

def main():
    file_path = sys.argv[1]

    index = clang.cindex.Index.create()
    tu = index.parse(file_path)

    function_list=[]

    for cursor in tu.cursor.get_children():
        if (
            cursor.kind in [
                clang.cindex.CursorKind.FUNCTION_DECL,
                clang.cindex.CursorKind.CXX_METHOD,
            ]
        ):
            function_list.append({
                "cursor":cursor,
                "args_cursor":[arg for arg in cursor.get_arguments()]
            })

    output=""
    for func in function_list:
        # parameters
        cursor=func["cursor"]
        args_pass=",".join([f"args.{arg.spelling}" for arg in func["args_cursor"]])
        args_declare=[f"{arg.type.spelling} {arg.spelling}" for arg in func["args_cursor"]]
        args_declare_in_struct="".join([f"{arg};" for arg in args_declare])
        args_struct=f"__{cursor.spelling}_args__"
        # struct
        output+="typedef struct {"
        output+=f"{args_declare_in_struct}"
        output+="}"
        output+=f" {args_struct};"
        # macro
        output+=f"\n#define {cursor.spelling}_call(...) ""({"
        output+=f"{args_struct} args=""{__VA_ARGS__};"
        output+=f"{cursor.spelling}({args_pass});"
        output+="})\n"
    
    print(output)

if __name__ == '__main__':
    main()
