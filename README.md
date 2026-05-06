# Stepper-Dev-Kit

An efficient and modular toolkit designed for **stepper development**.

This kit provides the core logic and utilities needed to streamline your stepper devplopment or product engineering.

## File Structure

- `cd/`: Some scripts for CD.
- `ci/`: Some scripts for CI.
- `dev/`: Some scripts for developer.
- `env/`: Some environment variables for CI/CD and development.
- `examples/`: For CI to build examples.
- `include/`: The include headers.
- `src/`: The source codes.
- `tests/`: For CI to build tests.

## Getting Started

### Integration

- 
    **CMake**:  
    ```cmake
    include(FetchContent)

    FetchContent_Declare(
        cxs_stepper_dev_kit
        GIT_REPOSITORY https://github.com/XIAN-SHENG-576692/Stepper-Dev-Kit.git
        GIT_TAG        latest
        GIT_SHALLOW    TRUE
    )
    FetchContent_MakeAvailable(cxs_stepper_dev_kit)
    ```

### Trying the Examples

You don't need to build everything from scratch to see it in action. Our **CI/CD pipeline** automatically builds a functional examples for every release.

- 
    **Manually download**:  
    [![Download examples.zip](https://img.shields.io/github/v/release/XIAN-SHENG-576692/Stepper-Dev-Kit?label=Download%20examples.zip&style=flat)](https://github.com/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/download/latest/examples.zip)
- 
    **cURL and Wget**:  
    ```bash
    curl -s https://api.github.com/repos/XIAN-SHENG-576692/Stepper-Dev-Kit/releases/latest \
    | grep "browser_download_url" \
    | cut -d : -f 2,3 \
    | tr -d \" \
    | grep "examples.zip" \
    | wget -qi -
    ```

## Development and Testing

If you wish to contribute or modify the kit, you can leverage the automated tools provided:
- **Builds and Tests**: Use scripts in `ci/`
    - To build `examples/` and `tests/`.
    - To run `tests/`.
- **Developing**: Use scripts in `dev/` for an improved development experience.
