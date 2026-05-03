# Stepper-Dev-Kit

An efficient and modular toolkit designed for **stepper development**.

This kit provides the core logic and utilities needed to streamline your stepper devplopment or product engineering.

## File Structure

- `cicd/`: Some scripts for CI/CD.
- `examples/`: For CI/CD to build examples.
- `dev/`: Some scripts for developer.
- `src/`: The source codes.
- `tests/`: For CI/CD to build tests.

## Getting Started

### Integration

To use this toolkit in your own project, simply include the files located in the `src/` directory.

The `src.zip` are available for download in the latest release:

- 
    **Manually download**:  
    [![Download src.zip](https://img.shields.io/github/v/release/XIAN-SHENG-576692/Stepper-Dev-Kit?label=Download%20src.zip&style=flat)](https://github.com/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/download/latest/src.zip)
- 
    **Wget**:  
    ```bash
    curl -s https://api.github.com/repos/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/latest \
    | grep "browser_download_url" \
    | cut -d : -f 2,3 \
    | tr -d \" \
    | grep "src.zip" \
    | wget -qi -
    ```
- 
    **CMake**:  
    ```cmake
    include(FetchContent)

    FetchContent_Declare(
        cxs_stepper_dev_kit
        URL https://github.com/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/download/latest/src.zip
    )
    FetchContent_MakeAvailable(cxs_stepper_dev_kit)
    ```

### Trying the Examples

You don't need to build everything from scratch to see it in action. Our **CI/CD pipeline** automatically builds a functional examples for every release:
1. Navigate to the **Releases** section of this repository.
2. Download the latest `examples.zip` artifact.
3. Run the executable to explore the toolkit's capabilities.

[![Download examples.zip](https://img.shields.io/github/v/release/XIAN-SHENG-576692/Stepper-Dev-Kit?label=Download%20examples.zip&style=flat)](
https://github.com/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/download/latest/examples.zip)

## Development and Testing

If you wish to contribute or modify the kit, you can leverage the automated tools provided:
- **Builds**: Use scripts in `cicd/` to set up your local environment.
- **Developing**: Use scripts in `dev/` for an improved development experience.
- **Testing**: Run scripts in `tests/` to validate any changes you make to the source code.
