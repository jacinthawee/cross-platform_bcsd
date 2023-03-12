
void PEM_proc_type(char *buf,int type)

{
  char *pcVar1;
  
  if (type == 10) {
    pcVar1 = "ENCRYPTED";
  }
  else if (type == 0x1e) {
    pcVar1 = "MIC-CLEAR";
  }
  else if (type == 0x14) {
    pcVar1 = "MIC-ONLY";
  }
  else {
    pcVar1 = "BAD-TYPE";
  }
  (*(code *)PTR_BUF_strlcat_006a6f68)(buf,"Proc-Type: 4,",0x400);
  (*(code *)PTR_BUF_strlcat_006a6f68)(buf,pcVar1,0x400);
                    /* WARNING: Could not recover jumptable at 0x0056affc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BUF_strlcat_006a6f68)(buf,"\n",0x400);
  return;
}

