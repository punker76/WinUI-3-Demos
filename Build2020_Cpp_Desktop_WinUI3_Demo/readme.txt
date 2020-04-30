Install Visual Studio Enterprise 2019 Int Preview: 
https://aka.ms/vs/dogfood/install 

If you have problems restoring, try manually adding the feeds in the nuget.

WinUI 3 in Desktop requires a Windows Application Packaging Project (WAP) and this WAP was modified to make it with the current bits of WinUI 3.

In case you need to create a new WAP project, you should do the following steps:
- In the  project, right-click the app.manifest and go to Properties. There change the value of Copy To Output Directory to Copy always
- Add this snippet to the .wapproj:

<Target Name="AfterBuild">    
<!-- initial copy -->   
<Copy SourceFiles="$(OutDir)AppxManifest.xml"
          DestinationFiles="$(MSBuildThisFileDirectory)Override.Appxmanifest.xml"
          Condition="!Exists('$(MSBuildThisFileDirectory)Override.Appxmanifest.xml')"/>
    <Copy SourceFiles="$(MSBuildThisFileDirectory)Override.Appxmanifest.xml" DestinationFiles="$(OutDir)AppxManifest.xml"/>
  </Target>

- Build 
- Open the Override.AppxManifest.xml file this places next to the .wapproj, and change the EntryPoint to EntryPoint="Windows.FullTrustApplication"
- Build the project again

From there you should be able to build and make changes as you want, w/o needing to re-run these steps
