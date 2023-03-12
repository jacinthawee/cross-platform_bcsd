
int SSL_CTX_use_RSAPrivateKey_ASN1(SSL_CTX *ctx,uchar *d,long len)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  uchar *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_20 = d;
  iVar2 = (*(code *)PTR_d2i_RSAPrivateKey_006a79e4)(0,&local_20);
  if (iVar2 == 0) {
    piVar8 = (int *)&DAT_000000b2;
    piVar3 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb2,0xd,&DAT_00649450,0x246);
    goto LAB_004b62fc;
  }
  piVar3 = (int *)ssl_cert_inst(&ctx->cert);
  if (piVar3 == (int *)0x0) {
    uVar9 = 0x41;
    uVar6 = 0x200;
LAB_004b633c:
    piVar8 = (int *)0xb1;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb1,uVar9,&DAT_00649450,uVar6);
  }
  else {
    piVar4 = (int *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    if (piVar4 == (int *)0x0) {
      uVar9 = 6;
      uVar6 = 0x204;
      piVar3 = piVar4;
      goto LAB_004b633c;
    }
    (*(code *)PTR_RSA_up_ref_006a7f98)(iVar2);
    piVar8 = (int *)&DAT_00000006;
    iVar5 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(piVar4,6,iVar2);
    if (iVar5 < 1) {
      piVar3 = (int *)0x0;
      (*(code *)PTR_RSA_free_006a7600)(iVar2);
    }
    else {
      piVar8 = piVar4;
      piVar3 = (int *)ssl_set_pkey(ctx->cert);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar4);
    }
  }
  (*(code *)PTR_RSA_free_006a7600)(iVar2);
LAB_004b62fc:
  if (local_1c == *(int *)puVar1) {
    return (int)piVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar8 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xae,0x43,&DAT_00649450,0x253);
    return 0;
  }
  iVar5 = ssl_cert_inst(iVar2 + 0xb0);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xae,0x41,&DAT_00649450,599);
    return 0;
  }
  piVar3 = *(int **)(iVar2 + 0xb0);
  iVar2 = (*(code *)PTR_ssl_cert_type_006a8058)(0,piVar8);
  if (iVar2 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0xf7,&DAT_00649450,0xb4);
    iVar5 = 0;
  }
  else {
    if (piVar3[iVar2 * 3 + 0xc] != 0) {
      iVar5 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0x41,&DAT_00649450,0xbc);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
        return 0;
      }
      (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar5,piVar8);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar5);
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      if (((*piVar8 != 6) ||
          (uVar7 = (*(code *)PTR_RSA_flags_006a83c8)(piVar8[5]), (uVar7 & 1) == 0)) &&
         (iVar5 = (*(code *)PTR_X509_check_private_key_006a707c)(piVar3[iVar2 * 3 + 0xc],piVar8),
         iVar5 == 0)) {
        (*(code *)PTR_X509_free_006a6e90)(piVar3[iVar2 * 3 + 0xc]);
        piVar3[iVar2 * 3 + 0xc] = 0;
        return 0;
      }
    }
    if (piVar3[iVar2 * 3 + 0xd] != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    CRYPTO_add_lock(piVar8 + 2,1,10,"ssl_rsa.c",0xda);
    iVar5 = 1;
    piVar3[iVar2 * 3 + 0xd] = (int)piVar8;
    piVar3[1] = 0;
    *piVar3 = (int)(piVar3 + iVar2 * 3 + 0xc);
  }
  return iVar5;
}

