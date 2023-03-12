
undefined4 fd_gets(BIO *param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  pcVar6 = param_2;
  if (param_2 < param_2 + param_3 + -1) {
    if (param_2 != (char *)0x0) {
      piVar3 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      do {
        puVar2 = PTR_read_006a9b10;
        *piVar3 = 0;
        iVar4 = (*(code *)puVar2)(param_1->num,pcVar6,1);
        BIO_clear_flags(param_1,0xf);
        if (iVar4 < 1) {
          if (1 < iVar4 + 1U) goto LAB_0052130c;
          iVar4 = *piVar3;
          if (iVar4 != 0x47) {
            if (iVar4 < 0x48) {
              if (iVar4 != 4) {
                if (iVar4 == 0xb) {
                  BIO_set_flags(param_1,9);
                }
                goto LAB_0052130c;
              }
            }
            else if ((iVar4 != 0x86) && ((iVar4 < 0x86 || (1 < iVar4 - 0x95U)))) goto LAB_0052130c;
          }
          BIO_set_flags(param_1,9);
          goto LAB_0052130c;
        }
        if ((*pcVar6 == '\n') || (pcVar6 = pcVar6 + 1, param_2 + param_3 + -1 == pcVar6))
        goto LAB_0052130c;
      } while (pcVar6 != (char *)0x0);
    }
    SUB_00000000 = 0;
    cVar1 = *param_2;
  }
  else {
LAB_0052130c:
    *pcVar6 = '\0';
    cVar1 = *param_2;
  }
  if (cVar1 == '\0') {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00521340. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_strlen_006a9a24)(param_2);
  return uVar5;
}

