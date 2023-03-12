
char * DSO_merge(DSO *dso,char *filespec1,char *filespec2)

{
  char *pcVar1;
  DSO_MERGER_FUNC UNRECOVERED_JUMPTABLE;
  
  if (filespec1 == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x84,0x43,"dso_lib.c",399);
  }
  else if (-1 < dso->flags << 0x1f) {
    if (dso->merger != (DSO_MERGER_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0010b7d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pcVar1 = (*dso->merger)(dso,filespec1,filespec2);
      return pcVar1;
    }
    UNRECOVERED_JUMPTABLE = dso->meth->dso_merger;
    if (UNRECOVERED_JUMPTABLE != (DSO_MERGER_FUNC)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0010b804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pcVar1 = (*UNRECOVERED_JUMPTABLE)(dso,filespec1,filespec2);
      return pcVar1;
    }
  }
  return (char *)0x0;
}

