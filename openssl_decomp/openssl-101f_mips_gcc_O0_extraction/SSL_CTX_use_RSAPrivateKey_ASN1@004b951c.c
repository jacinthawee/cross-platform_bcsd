
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_20 = d;
  iVar2 = (*(code *)PTR_d2i_RSAPrivateKey_006a8ad4)(0,&local_20);
  if (iVar2 == 0) {
    piVar8 = (int *)0xb2;
    piVar3 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb2,0xd,&DAT_00649ed0,0x25f);
    goto LAB_004b95fc;
  }
  piVar3 = (int *)ssl_cert_inst(&ctx->cert);
  if (piVar3 == (int *)0x0) {
    uVar9 = 0x41;
    uVar6 = 0x215;
LAB_004b963c:
    piVar8 = (int *)0xb1;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb1,uVar9,&DAT_00649ed0,uVar6);
  }
  else {
    piVar4 = (int *)(*(code *)PTR_EVP_PKEY_new_006a8710)();
    if (piVar4 == (int *)0x0) {
      uVar9 = 6;
      uVar6 = 0x21a;
      piVar3 = piVar4;
      goto LAB_004b963c;
    }
    (*(code *)PTR_RSA_up_ref_006a9120)(iVar2);
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(piVar4,6,iVar2);
    piVar8 = piVar4;
    piVar3 = (int *)ssl_set_pkey(ctx->cert);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
  }
  (*(code *)PTR_RSA_free_006a86f0)(iVar2);
LAB_004b95fc:
  if (local_1c == *(int *)puVar1) {
    return (int)piVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piVar8 != (int *)0x0) {
    iVar5 = ssl_cert_inst(iVar2 + 0xb0);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xae,0x41,&DAT_00649ed0,0x272);
      return 0;
    }
    piVar3 = *(int **)(iVar2 + 0xb0);
    iVar2 = (*(code *)PTR_ssl_cert_type_006a91a8)(0,piVar8);
    if (iVar2 < 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc1,0xf7,&DAT_00649ed0,0xbd);
      iVar5 = 0;
    }
    else {
      if (piVar3[iVar2 * 3 + 0xc] != 0) {
        uVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar6,piVar8);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar6);
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        if (((*piVar8 != 6) ||
            (uVar7 = (*(code *)PTR_RSA_flags_006a94e0)(piVar8[5]), (uVar7 & 1) == 0)) &&
           (iVar5 = (*(code *)PTR_X509_check_private_key_006a817c)(piVar3[iVar2 * 3 + 0xc],piVar8),
           iVar5 == 0)) {
          (*(code *)PTR_X509_free_006a7f90)(piVar3[iVar2 * 3 + 0xc]);
          piVar3[iVar2 * 3 + 0xc] = 0;
          return 0;
        }
      }
      if (piVar3[iVar2 * 3 + 0xd] != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      CRYPTO_add_lock(piVar8 + 2,1,10,"ssl_rsa.c",0xdb);
      iVar5 = 1;
      piVar3[iVar2 * 3 + 0xd] = (int)piVar8;
      piVar3[1] = 0;
      *piVar3 = (int)(piVar3 + iVar2 * 3 + 0xc);
    }
    return iVar5;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xae,0x43,&DAT_00649ed0,0x26d);
  return 0;
}

