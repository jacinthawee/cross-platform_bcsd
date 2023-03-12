
int dgram_write(BIO *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  psVar5 = (short *)param_1->ptr;
  piVar1 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
  *piVar1 = 0;
  if (*(int *)(psVar5 + 0xe) == 0) {
    uVar2 = 0x10;
    if (*psVar5 != 2) {
      uVar2 = 0x1c;
    }
    iVar3 = (*(code *)PTR_sendto_006aaacc)(param_1->num,param_2,param_3,0,psVar5,uVar2);
  }
  else {
    iVar3 = (*(code *)PTR_write_006aab28)(param_1->num,param_2,param_3);
  }
  BIO_clear_flags(param_1,0xf);
  if (0 < iVar3) {
    return iVar3;
  }
  if (1 < iVar3 + 1U) {
    return iVar3;
  }
  iVar4 = *piVar1;
  if (iVar4 != 0x47) {
    if (iVar4 < 0x48) {
      if ((iVar4 == 4) || (iVar4 == 0xb)) goto LAB_0052d8e0;
    }
    else if (iVar4 - 0x95U < 2) goto LAB_0052d8e0;
    return iVar3;
  }
LAB_0052d8e0:
  BIO_set_flags(param_1,10);
  *(int *)(psVar5 + 0x10) = *piVar1;
  return iVar3;
}

