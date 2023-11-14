static b32 BuildProtectedModeBootSectorImage(build_context *BuildContext)
{
    PushSubTarget(BuildContext, "boot_sector");
    AddSourceFile(BuildContext, "\\x86_bios\\protected_mode_os\\boot_sector\\entry.s");
    AddCompilerFlags(BuildContext, "-f bin");
    SetOuputBinaryPath(BuildContext, "\\boot_sector.img");
    SetCompilerIncludePath(BuildContext, BuildContext->RootDirectoryPath);
    b32 BuildSuccess = AssembleWithNasm(BuildContext);
    PopSubTarget(BuildContext);
    return BuildSuccess;
}