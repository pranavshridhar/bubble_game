# Dockerfile for building and running tests
# This Dockerfile is going to build and run the tests for the project.
# This is going to remain as it is, for the sake of reliability.

# Use Ubuntu with a recent g++ supporting C++23
FROM ubuntu:24.04

# Set up working directory
WORKDIR /app

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    clang \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

# Copy the entire project into the image
COPY . .

# Build and run the tests
RUN make test_build

# Run the tests
CMD ["./test_runner"]