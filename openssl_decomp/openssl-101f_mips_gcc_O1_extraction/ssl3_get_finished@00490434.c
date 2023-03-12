
int ssl3_get_finished(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined uVar6;
  int *piVar7;
  int local_18;
  undefined4 *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piVar7 = &local_18;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))();
  if (local_18 != 0) {
    iVar4 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar4 + 0x180) == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8c,0x9a,"s3_both.c",0x103,piVar7);
      param_3 = 10;
    }
    else {
      *(undefined4 *)(iVar4 + 0x180) = 0;
      if (iVar2 == *(int *)(iVar4 + 0x338)) {
        iVar4 = (*(code *)PTR_CRYPTO_memcmp_006a9088)
                          (*(undefined4 *)(param_1 + 0x40),iVar4 + 0x2b8,iVar2);
        if (iVar4 == 0) {
          uVar6 = (undefined)iVar2;
          param_3 = iVar2;
          if (*(int *)(param_1 + 4) == 0x2000) {
            if (0x40 < iVar2) {
              (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_both.c",0x11d,"i <= EVP_MAX_MD_SIZE");
            }
            param_2 = *(int *)(param_1 + 0x58) + 0x2b8;
            (*(code *)PTR_memcpy_006aabf4)(*(int *)(param_1 + 0x58) + 0x394);
            iVar2 = 1;
            *(undefined *)(*(int *)(param_1 + 0x58) + 0x3d4) = uVar6;
          }
          else {
            if (0x40 < iVar2) {
              (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_both.c",0x124,"i <= EVP_MAX_MD_SIZE");
            }
            param_2 = *(int *)(param_1 + 0x58) + 0x2b8;
            (*(code *)PTR_memcpy_006aabf4)(*(int *)(param_1 + 0x58) + 0x3d5);
            iVar2 = 1;
            *(undefined *)(*(int *)(param_1 + 0x58) + 0x415) = uVar6;
          }
          goto LAB_004904f8;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8c,0x95,"s3_both.c",0x115);
        param_3 = 0x33;
      }
      else {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8c,0x6f,"s3_both.c",0x10e);
        param_3 = 0x32;
      }
    }
    param_2 = 2;
    ssl3_send_alert(param_1);
    iVar2 = 0;
  }
LAB_004904f8:
  if (local_14 == *(undefined4 **)puVar1) {
    return iVar2;
  }
  puVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (puVar3[0xd] == param_2) {
    uVar5 = 1;
    iVar2 = 0;
    **(undefined **)(puVar3[0xf] + 4) = 1;
    puVar3[0x12] = 0;
    puVar3[0xd] = param_3;
    puVar3[0x11] = 1;
  }
  else {
    iVar2 = puVar3[0x12];
    uVar5 = puVar3[0x11];
  }
  iVar2 = ssl3_write_bytes(puVar3,0x14,*(int *)(puVar3[0xf] + 4) + iVar2,uVar5);
  if (iVar2 < 0) {
    iVar4 = -1;
  }
  else if (iVar2 == puVar3[0x11]) {
    if ((code *)puVar3[0x19] != (code *)0x0) {
      (*(code *)puVar3[0x19])
                (1,*puVar3,0x14,*(undefined4 *)(puVar3[0xf] + 4),iVar2 + puVar3[0x12],puVar3,
                 puVar3[0x1a]);
      return 1;
    }
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    puVar3[0x11] = puVar3[0x11] - iVar2;
    puVar3[0x12] = puVar3[0x12] + iVar2;
  }
  return iVar4;
}

