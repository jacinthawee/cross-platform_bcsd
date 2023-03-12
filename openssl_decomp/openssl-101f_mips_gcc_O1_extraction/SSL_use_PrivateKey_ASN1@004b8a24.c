
int SSL_use_PrivateKey_ASN1(int pk,SSL *ssl,uchar *d,long len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uchar *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_20 = d;
  iVar2 = (*(code *)PTR_d2i_PrivateKey_006a94f0)(pk,0,&local_20);
  if (iVar2 == 0) {
    iVar6 = 0xca;
    iVar3 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xca,0xd,&DAT_00649ed0,0x172);
  }
  else {
    iVar3 = ssl_cert_inst(&ssl->cert);
    if (iVar3 == 0) {
      iVar6 = 0xc9;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc9,0x41,&DAT_00649ed0,0x132);
    }
    else {
      iVar6 = iVar2;
      iVar3 = ssl_set_pkey(ssl->cert);
    }
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
  }
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar6 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xab,0x43,&DAT_00649ed0,0x17f);
    return 0;
  }
  iVar3 = ssl_cert_inst(iVar2 + 0xb0);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xab,0x41,&DAT_00649ed0,0x184);
    return 0;
  }
  piVar8 = *(int **)(iVar2 + 0xb0);
  iVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar6);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0x10c,&DAT_00649ed0,0x192);
    return 0;
  }
  iVar3 = (*(code *)PTR_ssl_cert_type_006a91a8)(iVar6,iVar2);
  if (iVar3 < 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0xf7,&DAT_00649ed0,0x199);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
    return 0;
  }
  if (piVar8[iVar3 * 3 + 0xd] != 0) {
    (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(iVar2);
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    piVar7 = (int *)piVar8[iVar3 * 3 + 0xd];
    if (*piVar7 == 6) {
      uVar5 = (*(code *)PTR_RSA_flags_006a94e0)(piVar7[5]);
      if ((uVar5 & 1) != 0) goto LAB_004b8c28;
      piVar7 = (int *)piVar8[iVar3 * 3 + 0xd];
    }
    iVar4 = (*(code *)PTR_X509_check_private_key_006a817c)(iVar6,piVar7);
    if (iVar4 == 0) {
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar8[iVar3 * 3 + 0xd]);
      puVar1 = PTR_ERR_clear_error_006a7fe0;
      piVar8[iVar3 * 3 + 0xd] = 0;
      (*(code *)puVar1)();
    }
  }
LAB_004b8c28:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
  if (piVar8[iVar3 * 3 + 0xc] != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,"ssl_rsa.c",0x1bd);
  piVar8[iVar3 * 3 + 0xc] = iVar6;
  piVar8[1] = 0;
  *piVar8 = (int)(piVar8 + iVar3 * 3 + 0xc);
  return 1;
}

