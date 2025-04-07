# Build the main executable
[working-directory: 'build']
build:
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
    make

# Build the main executable in release mode
[working-directory: 'build']
release:
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make

# Run the main executable
[positional-arguments]
run path: build
    @build/bin/kuristo $1
