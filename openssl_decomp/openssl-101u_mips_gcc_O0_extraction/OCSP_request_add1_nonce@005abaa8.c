
int OCSP_request_add1_nonce(OCSP_REQUEST *req,uchar *val,int len)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  uint uVar9;
  int iStack_80;
  undefined4 auStack_7c [2];
  int iStack_74;
  int *piStack_6c;
  uint uStack_64;
  undefined *puStack_60;
  uchar *puStack_5c;
  OCSP_REQINFO *pOStack_58;
  code *pcStack_54;
  undefined4 local_40;
  undefined *local_38;
  int local_30;
  int local_2c [2];
  int local_24;
  int *local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  piVar3 = (int *)&SUB_00000010;
  if (0 < len) {
    piVar3 = (int *)len;
  }
  local_38 = &_gp;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pOStack_58 = req->tbsRequest;
  local_2c[0] = (*(code *)PTR_ASN1_object_size_006a83e4)(0,piVar3,4);
  piVar8 = (int *)0x165;
  pcVar6 = "ocsp_ext.c";
  local_24 = (**(code **)(local_38 + -0x7dd8))(local_2c[0]);
  if (local_24 == 0) {
    uStack_64 = 0;
  }
  else {
    local_40 = 0;
    piVar8 = piVar3;
    local_30 = local_24;
    (**(code **)(local_38 + -0x69f8))(&local_30,0,piVar3,4);
    if (val == (uchar *)0x0) {
      iVar2 = (**(code **)(local_38 + -0x786c))(local_30);
      if (0 < iVar2) goto LAB_005abb74;
      uStack_64 = 0;
      pcVar6 = (char *)piVar3;
    }
    else {
      (**(code **)(local_38 + -0x52f4))(local_30,val,piVar3);
LAB_005abb74:
      piVar8 = local_2c;
      pcVar6 = &DAT_0000016e;
      local_40 = 2;
      iVar2 = (**(code **)(local_38 + -0x5e80))(&pOStack_58->requestExtensions,0x16e,piVar8,0);
      uStack_64 = (uint)(iVar2 != 0);
    }
    if (local_24 != 0) {
      (**(code **)(local_38 + -0x7f58))();
    }
  }
  if (local_1c == *(int **)puStack_60) {
    return uStack_64;
  }
  pcStack_54 = OCSP_basic_add1_nonce;
  piVar5 = local_1c;
  (**(code **)(local_38 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piVar3 = (int *)&SUB_00000010;
  if (0 < (int)piVar8) {
    piVar3 = piVar8;
  }
  piStack_6c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = *piVar5;
  puStack_5c = val;
  auStack_7c[0] = (*(code *)PTR_ASN1_object_size_006a83e4)(0,piVar3,4);
  pcVar7 = "ocsp_ext.c";
  iStack_74 = (*(code *)PTR_CRYPTO_malloc_006a7008)(auStack_7c[0],"ocsp_ext.c",0x165);
  if (iStack_74 == 0) {
    uVar9 = 0;
    goto LAB_005abd20;
  }
  iStack_80 = iStack_74;
  (*(code *)PTR_ASN1_put_object_006a83e8)(&iStack_80,0,piVar3,4,0);
  if ((int *)pcVar6 == (int *)0x0) {
    iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(iStack_80);
    if (0 < iVar4) goto LAB_005abce0;
    uVar9 = 0;
    pcVar7 = (char *)piVar3;
  }
  else {
    (*(code *)PTR_memcpy_006a9aec)(iStack_80,pcVar6,piVar3);
LAB_005abce0:
    pcVar7 = &DAT_0000016e;
    iVar2 = (*(code *)PTR_X509V3_add1_i2d_006a8f60)(iVar2 + 0x10,0x16e,auStack_7c,0,2);
    uVar9 = (uint)(iVar2 != 0);
  }
  if (iStack_74 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
LAB_005abd20:
  if (piStack_6c == *(int **)puVar1) {
    return uVar9;
  }
  piVar3 = piStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_X509v3_get_ext_by_NID_006a8f48)
                    (*(undefined4 *)(*piVar3 + 0xc),0x16e,0xffffffff);
  iVar4 = (*(code *)PTR_X509v3_get_ext_by_NID_006a8f48)
                    (*(undefined4 *)(*(int *)pcVar7 + 0x10),0x16e,0xffffffff);
  if (-1 < iVar2) {
    if (iVar4 < 0) {
      uVar9 = 0xffffffff;
    }
    else {
      iVar2 = (*(code *)PTR_X509v3_get_ext_006a8f54)(*(undefined4 *)(*piVar3 + 0xc),iVar2);
      iVar4 = (*(code *)PTR_X509v3_get_ext_006a8f54)(*(undefined4 *)(*(int *)pcVar7 + 0x10),iVar4);
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)
                        (*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar4 + 8));
      uVar9 = (uint)(iVar2 == 0);
    }
    return uVar9;
  }
  iVar2 = 3;
  if (iVar4 < 0) {
    iVar2 = 2;
  }
  return iVar2;
}

