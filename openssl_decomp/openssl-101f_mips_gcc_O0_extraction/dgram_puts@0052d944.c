
int dgram_puts(BIO *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  psVar6 = (short *)param_1->ptr;
  piVar2 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  *piVar2 = 0;
  if (*(int *)(psVar6 + 0xe) == 0) {
    uVar3 = 0x10;
    if (*psVar6 != 2) {
      uVar3 = 0x1c;
    }
    iVar4 = (*(code *)PTR_sendto_006aaacc)(param_1->num,param_2,uVar1,0,psVar6,uVar3);
  }
  else {
    iVar4 = (*(code *)PTR_write_006aab28)(param_1->num,param_2,uVar1);
  }
  BIO_clear_flags(param_1,0xf);
  if (0 < iVar4) {
    return iVar4;
  }
  if (1 < iVar4 + 1U) {
    return iVar4;
  }
  iVar5 = *piVar2;
  if (iVar5 != 0x47) {
    if (iVar5 < 0x48) {
      if ((iVar5 == 4) || (iVar5 == 0xb)) goto LAB_0052da54;
    }
    else if (iVar5 - 0x95U < 2) goto LAB_0052da54;
    return iVar4;
  }
LAB_0052da54:
  BIO_set_flags(param_1,10);
  *(int *)(psVar6 + 0x10) = *piVar2;
  return iVar4;
}

