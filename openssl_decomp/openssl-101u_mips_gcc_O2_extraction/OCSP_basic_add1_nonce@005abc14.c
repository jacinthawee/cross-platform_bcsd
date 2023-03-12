
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp,uchar *val,int len)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  OCSP_RESPDATA *pOVar7;
  int local_30;
  undefined4 local_2c [2];
  int local_24;
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)&SUB_00000010;
  if (0 < len) {
    piVar2 = (int *)len;
  }
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pOVar7 = resp->tbsResponseData;
  local_2c[0] = (*(code *)PTR_ASN1_object_size_006a83e4)(0,piVar2,4);
  pcVar5 = "ocsp_ext.c";
  local_24 = (*(code *)PTR_CRYPTO_malloc_006a7008)(local_2c[0],"ocsp_ext.c",0x165);
  if (local_24 == 0) {
    uVar6 = 0;
    goto LAB_005abd20;
  }
  local_30 = local_24;
  (*(code *)PTR_ASN1_put_object_006a83e8)(&local_30,0,piVar2,4,0);
  if (val == (uchar *)0x0) {
    iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(local_30);
    if (0 < iVar3) goto LAB_005abce0;
    uVar6 = 0;
    pcVar5 = (char *)piVar2;
  }
  else {
    (*(code *)PTR_memcpy_006a9aec)(local_30,val,piVar2);
LAB_005abce0:
    pcVar5 = &DAT_0000016e;
    iVar3 = (*(code *)PTR_X509V3_add1_i2d_006a8f60)(&pOVar7->responseExtensions,0x16e,local_2c,0,2);
    uVar6 = (uint)(iVar3 != 0);
  }
  if (local_24 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
LAB_005abd20:
  if (local_1c == *(int **)puVar1) {
    return uVar6;
  }
  piVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_X509v3_get_ext_by_NID_006a8f48)
                    (*(undefined4 *)(*piVar2 + 0xc),0x16e,0xffffffff);
  iVar4 = (*(code *)PTR_X509v3_get_ext_by_NID_006a8f48)
                    (*(undefined4 *)(*(int *)pcVar5 + 0x10),0x16e,0xffffffff);
  if (-1 < iVar3) {
    if (iVar4 < 0) {
      uVar6 = 0xffffffff;
    }
    else {
      iVar3 = (*(code *)PTR_X509v3_get_ext_006a8f54)(*(undefined4 *)(*piVar2 + 0xc),iVar3);
      iVar4 = (*(code *)PTR_X509v3_get_ext_006a8f54)(*(undefined4 *)(*(int *)pcVar5 + 0x10),iVar4);
      iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)
                        (*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar4 + 8));
      uVar6 = (uint)(iVar3 == 0);
    }
    return uVar6;
  }
  iVar3 = 3;
  if (iVar4 < 0) {
    iVar3 = 2;
  }
  return iVar3;
}

