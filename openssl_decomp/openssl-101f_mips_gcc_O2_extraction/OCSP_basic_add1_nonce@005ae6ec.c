
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp,uchar *val,int len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  OCSP_RESPDATA *pOVar7;
  int local_30;
  undefined4 local_2c [2];
  int local_24;
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = 0x10;
  if (0 < len) {
    iVar2 = len;
  }
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  pOVar7 = resp->tbsResponseData;
  local_2c[0] = (*(code *)PTR_ASN1_object_size_006a94fc)(0,iVar2,4);
  pcVar5 = "ocsp_ext.c";
  local_24 = (*(code *)PTR_CRYPTO_malloc_006a8108)(local_2c[0],"ocsp_ext.c",0x14a);
  if (local_24 == 0) {
    uVar6 = 0;
  }
  else {
    local_30 = local_24;
    (*(code *)PTR_ASN1_put_object_006a9500)(&local_30,0,iVar2,4,0);
    if (val == (uchar *)0x0) {
      (*(code *)PTR_RAND_pseudo_bytes_006a8664)(local_30,iVar2);
    }
    else {
      (*(code *)PTR_memcpy_006aabf4)(local_30,val,iVar2);
    }
    pcVar5 = &DAT_0000016e;
    iVar2 = (*(code *)PTR_X509V3_add1_i2d_006aa07c)(&pOVar7->responseExtensions,0x16e,local_2c,0,2);
    uVar6 = (uint)(iVar2 != 0);
    if (local_24 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
  }
  if (local_1c == *(int **)puVar1) {
    return uVar6;
  }
  piVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (*(undefined4 *)(*piVar4 + 0xc),0x16e,0xffffffff);
  iVar3 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)
                    (*(undefined4 *)(*(int *)pcVar5 + 0x10),0x16e,0xffffffff);
  if (-1 < iVar2) {
    if (iVar3 < 0) {
      uVar6 = 0xffffffff;
    }
    else {
      iVar2 = (*(code *)PTR_X509v3_get_ext_006aa070)(*(undefined4 *)(*piVar4 + 0xc),iVar2);
      iVar3 = (*(code *)PTR_X509v3_get_ext_006aa070)(*(undefined4 *)(*(int *)pcVar5 + 0x10),iVar3);
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)
                        (*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar3 + 8));
      uVar6 = (uint)(iVar2 == 0);
    }
    return uVar6;
  }
  iVar2 = 3;
  if (iVar3 < 0) {
    iVar2 = 2;
  }
  return iVar2;
}

