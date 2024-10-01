#!/bin/bash

# Navigate to the extension directory
cd ~/Documents/C++/ClownScript/Docs/Extention

# Install Yeoman and the generator for VS Code extensions
npm install -g yo generator-code

# Generate a new extension
yo code

# Optional: Check for funding information (not essential)
npm fund

# Create package.json file
touch package.json

# Check VSCodium version
codium --version

# Install dependencies
npm install

# Compile TypeScript files
npm run compile

# Install TypeScript as a development dependency
npm install typescript --save-dev

# Install VS Code type definitions
npm install --save-dev @types/vscode

# (If needed) Install vsce globally for packaging
sudo npm install -g vsce

# Package the extension into a .vsix file
vsce package

# (If required) Install a specific version of @types/vscode
npm install @types/vscode@1.50.0 --save-dev

# Package the extension again after updates
vsce package
