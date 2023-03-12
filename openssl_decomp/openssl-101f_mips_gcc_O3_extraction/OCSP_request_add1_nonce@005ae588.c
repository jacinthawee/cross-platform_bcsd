
int OCSP_request_add1_nonce(OCSP_REQUEST *req,uchar *val,int len)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
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
  undefined4 local_2c [2];
  int local_24;
  int *local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  iVar2 = 0x10;
  if (0 < len) {
    iVar2 = len;
  }
  local_38 = &_gp;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  pOStack_58 = req->tbsRequest;
  local_2c[0] = (*(code *)PTR_ASN1_object_size_006a94fc)(0,iVar2,4);
  puVar8 = (undefined4 *)0x14a;
  pcVar6 = "ocsp_ext.c";
  local_24 = (**(code **)(local_38 + -0x7dd8))(local_2c[0]);
  if (local_24 == 0) {
    uStack_64 = 0;
  }
  else {
    local_40 = 0;
    local_30 = local_24;
    (**(code **)(local_38 + -0x69e0))(&local_30,0,iVar2,4);
    if (val == (uchar *)0x0) {
      (**(code **)(local_38 + -0x787c))(local_30,iVar2);
    }
    else {
      (**(code **)(local_38 + -0x52ec))(local_30,val,iVar2);
    }
    puVar8 = local_2c;
    local_40 = 2;
    pcVar6 = (char *)0x16e;
    iVar2 = (**(code **)(local_38 + -0x5e64))(&pOStack_58->requestExtensions,0x16e,puVar8,0);
    uStack_64 = (uint)(iVar2 != 0);
    if (local_24 != 0) {
      (**(code **)(local_38 + -0x7f58))();
    }
  }
  if (local_1c == *(int **)puStack_60) {
    return uStack_64;
  }
  pcStack_54 = OCSP_basic_add1_nonce;
  piVar5 = local_1c;
  (**(code **)(local_38 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar3 = (undefined4 *)&SUB_00000010;
  if (0 < (int)puVar8) {
    puVar3 = puVar8;
  }
  piStack_6c = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar2 = *piVar5;
  puStack_5c = val;
  auStack_7c[0] = (*(code *)PTR_ASN1_object_size_006a94fc)(0,puVar3,4);
  pcVar7 = "ocsp_ext.c";
  iStack_74 = (*(code *)PTR_CRYPTO_malloc_006a8108)(auStack_7c[0],"ocsp_ext.c",0x14a);
  if (iStack_74 == 0) {
    uVar9 = 0;
  }
  else {
    iStack_80 = iStack_74;
    (*(code *)PTR_ASN1_put_object_006a9500)(&iStack_80,0,puVar3,4,0);
    if (pcVar6 == (char *)0x0) {
      (*(code *)PTR_RAND_pseudo_bytes_006a8664)(iStack_80,puVar3);
    }
    else {
      (*(code *)PTR_memcpy_006aabf4)(iStack_80,pcVar6,puVar3);
    }
    pcVar7 = &DAT_0000016e;
    iVar2 = (*(code *)PTR_X509V3_add1_i2d_006aa07c)(iVar2 + 0x10,0x16e,auStack_7c,0,2);
    uVar9 = (uint)(iVar2 != 0);
    if (iStack_74 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
  }
  if (piStack_6c == *(int **)puVar1) {
    return uVar9;
  }
  piVar5 = piStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (*(undefined4 *)(*piVar5 + 0xc),0x16e,0xffffffff);
  iVar4 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (*(undefined4 *)(*(int *)pcVar7 + 0x10),0x16e,0xffffffff);
  if (-1 < iVar2) {
    if (iVar4 < 0) {
      uVar9 = 0xffffffff;
    }
    else {
      iVar2 = (*(code *)PTR_X509v3_get_ext_006aa070)(*(undefined4 *)(*piVar5 + 0xc),iVar2);
      iVar4 = (*(code *)PTR_X509v3_get_ext_006aa070)(*(undefined4 *)(*(int *)pcVar7 + 0x10),iVar4);
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)
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

