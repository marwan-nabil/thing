static b32 BuildKernelImage(build_context *BuildContext)
{
    PushSubTarget(BuildContext, "kernel");
    AddSourceFile(BuildContext, "\\projects\\os_real\\kernel\\entry.s");
    AddCompilerFlags(BuildContext, "-f bin");
    SetOuputBinaryPath(BuildContext, "\\kernel.img");
    SetCompilerIncludePath(BuildContext, BuildContext->RootDirectoryPath);
    b32 BuildSuccess = AssembleWithNasm(BuildContext);
    PopSubTarget(BuildContext);
    return BuildSuccess;
}