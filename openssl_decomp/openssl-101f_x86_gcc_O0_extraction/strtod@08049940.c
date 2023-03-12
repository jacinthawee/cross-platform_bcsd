
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtod(char *__nptr,char **__endptr)

{
  float10 fVar1;
  
  fVar1 = (float10)(*(code *)PTR_strtod_082ef14c)();
  return (double)fVar1;
}

