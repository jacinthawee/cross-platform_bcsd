
char * DSO_merge(DSO *dso,char *filespec1,char *filespec2)

{
  char *pcVar1;
  DSO_MERGER_FUNC UNRECOVERED_JUMPTABLE;
  
  if ((dso == (DSO *)0x0) || (filespec1 == (char *)0x0)) {
    ERR_put_error(0x25,0x84,0x43,"dso_lib.c",0x175);
  }
  else if (((*(byte *)&dso->flags & 1) == 0) &&
          ((UNRECOVERED_JUMPTABLE = dso->merger, UNRECOVERED_JUMPTABLE != (DSO_MERGER_FUNC)0x0 ||
           (UNRECOVERED_JUMPTABLE = dso->meth->dso_merger,
           UNRECOVERED_JUMPTABLE != (DSO_MERGER_FUNC)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x081c63b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*UNRECOVERED_JUMPTABLE)(dso,filespec1,filespec2);
    return pcVar1;
  }
  return (char *)0x0;
}

