---
page_type: sample
languages:
- csharp
- cpp
products:
- dotnet
- WinUI
description: "These are some samples to demonstrate the usage of WinUI 3"
urlFragment: "update-this-to-unique-url-stub"
---

# Official Microsoft Sample

<!-- 
Guidelines on README format: https://review.docs.microsoft.com/help/onboard/admin/samples/concepts/readme-template?branch=master

Guidance on onboarding samples to docs.microsoft.com/samples: https://review.docs.microsoft.com/help/onboard/admin/samples/process/onboarding?branch=master

Taxonomies for products and languages: https://review.docs.microsoft.com/new-hope/information-architecture/metadata/taxonomies?branch=master
-->

Give a short description for your sample here. What does it do and why is it important?

## Contents

Outline the file contents of the repository. It helps users navigate the codebase, build configuration and any related assets.

| File/folder       | Description                                |
|-------------------|--------------------------------------------|
| `src`             | Sample source code.                        |
| `.gitignore`      | Define what to ignore at commit time.      |
| `CHANGELOG.md`    | List of changes to the sample.             |
| `CONTRIBUTING.md` | Guidelines for contributing to the sample. |
| `README.md`       | This README file.                          |
| `LICENSE`         | The license for the sample.                |

## Prerequisites


Configure your development environment (for detailed instructions see [Configure your dev environment](#configure-your-dev-environment)), install the WinUI 3.0 Preview 1 VSIX from the following link, and try out the WinUI 3 project templates.

<a href="https://aka.ms/winui3/previewdownload">Download the WinUI 3.0 Preview 1 VSIX</a>


### Configure your dev environment

Ensure that your development computer has Windows 10, version 1803 (build 17134), or a later version installed. WinUI 3 for desktop apps requires 1803 or a later OS version.

Install Visual Studio 2019, version 16.7 Preview 1. You can download this from  [Visual Studio Preview](https://visualstudio.microsoft.com/vs/preview).

You must include the following workloads when installing the Visual Studio Preview:

- .NET Desktop Development
- Universal Windows Platform development

To build C++ apps you must also include the following workloads:

- Desktop development with C++
- The *C++ (v142) Universal Windows Platform tools* optional component for the Universal Windows Platform workload

### Visual Studio project templates

To access the WinUI 3.0 Preview 1 and project templates, go to **https://aka.ms/winui3/previewdownload**

Download the Visual Studio Extension (`.vsix`) to add the WinUI project templates and NuGget package to Visual Studio 2019.

For directions on how to add the `.vsix` to Visual Studio, see [Finding and Using Visual Studio Extensions](https://docs.microsoft.com/visualstudio/ide/finding-and-using-visual-studio-extensions?view=vs-2019#install-without-using-the-manage-extensions-dialog-box).

After installing the `.vsix` extension you can create a new WinUI 3.0 project by searching for "WinUI" and selecting one of the available C# or C++ templates.



## Contributing

This project welcomes contributions and suggestions.  Most contributions require you to agree to a
Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us
the rights to use your contribution. For details, visit https://cla.opensource.microsoft.com.

When you submit a pull request, a CLA bot will automatically determine whether you need to provide
a CLA and decorate the PR appropriately (e.g., status check, comment). Simply follow the instructions
provided by the bot. You will only need to do this once across all repos using our CLA.

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/).
For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or
contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.
