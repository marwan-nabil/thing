b32 BuildRayTracer(build_context *BuildContext)
{
    if (BuildContext->argc < 4)
    {
        ConsolePrintColored("ERROR: invalid number of arguments for build ray_tracer ...\n", FOREGROUND_RED);
        DisplayHelp();
        return FALSE;
    }

    AddSourceFile(BuildContext, "\\projects\\ray_tracer\\main.cpp");

    AddCompilerFlags(BuildContext, "/nologo /Z7 /FC /Oi /GR- /EHa- /MTd /fp:fast /fp:except-");
    AddCompilerFlags(BuildContext, "/W4 /WX /wd4201 /wd4100 /wd4189 /wd4505 /wd4456 /wd4996 /wd4018");
    AddCompilerFlags(BuildContext, "/DENABLE_ASSERTIONS /D_CRT_SECURE_NO_WARNINGS");

    AddLinkerFlags(BuildContext, "/subsystem:console /incremental:no /opt:ref user32.lib gdi32.lib");

    if (strcmp(BuildContext->argv[2], "optimized") == 0)
    {
        AddCompilerFlags(BuildContext, "/O2");
    }
    else if (strcmp(BuildContext->argv[2], "non_optimized") == 0)
    {
        AddCompilerFlags(BuildContext, "/Od");
    }
    else
    {
        ConsoleSwitchColor(FOREGROUND_RED);
        printf("ERROR: invalid argument \"%s\" for build ray_tracer ...\n", BuildContext->argv[2]);
        ConsoleResetColor();
        DisplayHelp();
        return FALSE;
    }

    if (strcmp(BuildContext->argv[3], "1_lane") == 0)
    {
        AddCompilerFlags(BuildContext, "/DSIMD_NUMBEROF_LANES=1");
        SetOuputBinaryPath(BuildContext, "\\ray_tracer_1.exe");
    }
    else if (strcmp(BuildContext->argv[3], "4_lanes") == 0)
    {
        AddCompilerFlags(BuildContext, "/DSIMD_NUMBEROF_LANES=4");
        SetOuputBinaryPath(BuildContext, "\\ray_tracer_4.exe");
    }
    else if (strcmp(BuildContext->argv[3], "8_lanes") == 0)
    {
        AddCompilerFlags(BuildContext, "/DSIMD_NUMBEROF_LANES=8");
        SetOuputBinaryPath(BuildContext, "\\ray_tracer_8.exe");
    }
    else
    {
        ConsoleSwitchColor(FOREGROUND_RED);
        printf("ERROR: invalid argument \"%s\" for build ray_tracer ...\n", BuildContext->argv[3]);
        ConsoleResetColor();
        DisplayHelp();
        return FALSE;
    }

    b32 BuildSuccess = CompileCpp(BuildContext);
    return BuildSuccess;
}