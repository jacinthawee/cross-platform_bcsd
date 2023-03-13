
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  undefined *puVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  BIO *bio_00;
  int *piVar4;
  int aiStack_8e4 [2];
  int iStack_8dc;
  int iStack_8d8;
  int iStack_8d4;
  undefined *puStack_8d0;
  code *pcStack_8cc;
  undefined4 auStack_8c4 [3];
  int *piStack_8b8;
  undefined4 **ppuStack_8b4;
  undefined4 ***pppuStack_8b0;
  undefined *puStack_8a8;
  undefined4 ***pppuStack_8a0;
  int iStack_89c;
  undefined4 ****ppppuStack_898;
  int iStack_894;
  int iStack_890;
  int iStack_88c;
  undefined *puStack_888;
  code *pcStack_884;
  undefined4 **ppuStack_874;
  undefined *puStack_870;
  undefined4 **ppuStack_868;
  int iStack_864;
  undefined4 ****ppppuStack_860;
  code *pcStack_85c;
  undefined4 *puStack_850;
  undefined4 **ppuStack_84c;
  undefined *local_848;
  char *local_844;
  va_list local_840;
  undefined *local_838;
  undefined4 *local_830;
  undefined4 ****local_82c;
  undefined4 local_828;
  undefined4 ****local_824;
  undefined auStack_820 [4];
  undefined4 ***apppuStack_81c [512];
  BIO *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  ppppuStack_860 = apppuStack_81c;
  local_838 = &_gp;
  local_828 = 0x800;
  local_824 = (undefined4 ****)0x0;
  local_1c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  local_82c = ppppuStack_860;
  (*(code *)PTR_CRYPTO_push_info__006a88f4)("doapr()","b_print.c",0x32a);
  local_848 = auStack_820;
  ppuStack_874 = &local_830;
  puStack_850 = &local_828;
  ppppuStack_898 = &local_824;
  local_844 = format;
  local_840 = args;
  iVar2 = _dopr(&local_82c);
  if (iVar2 == 0) {
    (**(code **)(local_838 + -0x7f58))(local_824);
    ppppuVar3 = (undefined4 ****)0xffffffff;
  }
  else {
    if (local_824 == (undefined4 ****)0x0) {
      ppppuVar3 = (undefined4 ****)BIO_write(bio,ppppuStack_860,(int)local_830);
      ppppuStack_898 = ppppuStack_860;
      puStack_850 = local_830;
    }
    else {
      ppppuStack_898 = local_824;
      ppppuVar3 = (undefined4 ****)BIO_write(bio,local_824,(int)local_830);
      (**(code **)(local_838 + -0x7f58))(local_824);
      puStack_850 = local_830;
    }
    (**(code **)(local_838 + -0x64e8))();
    ppppuStack_860 = ppppuVar3;
  }
  if (local_1c == *(BIO **)puVar1) {
    return (int)ppppuVar3;
  }
  pcStack_85c = BIO_printf;
  bio_00 = local_1c;
  (**(code **)(local_838 + -0x5330))();
  puStack_888 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_8b4 = &puStack_850;
  puStack_870 = &_gp;
  iStack_864 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_868 = ppuStack_8b4;
  ppuStack_84c = ppuStack_874;
  iVar2 = BIO_vprintf(bio_00,(char *)ppppuStack_898,ppuStack_8b4);
  if (iStack_864 == *(int *)puStack_888) {
    return iVar2;
  }
  pcStack_884 = BIO_snprintf;
  iStack_89c = iStack_864;
  (**(code **)(puStack_870 + -0x5330))();
  puStack_8d0 = PTR___stack_chk_guard_006a9ae8;
  pppuStack_8b0 = &ppuStack_874;
  piStack_8b8 = &iStack_890;
  piVar4 = &iStack_894;
  ppppuVar3 = &ppppuStack_898;
  auStack_8c4[0] = 0;
  puStack_8a8 = &_gp;
  iStack_88c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppuStack_8a0 = pppuStack_8b0;
  iVar2 = _dopr(&iStack_89c);
  if ((iVar2 == 0) || (iStack_890 != 0)) {
    iStack_894 = -1;
  }
  else if (iStack_894 < 0) {
    iStack_894 = -1;
  }
  if (iStack_88c == *(int *)puStack_8d0) {
    return iStack_894;
  }
  pcStack_8cc = BIO_vsnprintf;
  aiStack_8e4[0] = iStack_88c;
  (**(code **)(puStack_8a8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_8d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = _dopr(aiStack_8e4,0,auStack_8c4,&iStack_8dc,&iStack_8d8,ppppuVar3,piVar4);
  if ((iVar2 == 0) || (iStack_8d8 != 0)) {
    iStack_8dc = -1;
  }
  else if (iStack_8dc < 0) {
    iStack_8dc = -1;
  }
  if (iStack_8d4 == *(int *)puVar1) {
    return iStack_8dc;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006a9a74)();
  return iVar2;
}

