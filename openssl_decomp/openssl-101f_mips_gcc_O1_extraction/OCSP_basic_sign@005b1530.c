
int OCSP_basic_sign(OCSP_BASICRESP *brsp,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,
                   stack_st_X509 *certs,ulong flags)

{
  uint uVar1;
  X509 *pXVar2;
  X509_NAME *pXVar3;
  int iVar4;
  X509 *pXVar5;
  stack_st_X509 *psVar6;
  char *pcVar7;
  X509 *pXVar8;
  OCSP_RESPID *pOVar9;
  X509 *pXVar10;
  undefined *puVar11;
  char *local_2c;
  
  puVar11 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  pXVar2 = (X509 *)key;
  pXVar8 = (X509 *)key;
  uVar1 = (*(code *)PTR_X509_check_private_key_006a817c)(signer);
  if (uVar1 == 0) {
    pXVar8 = (X509 *)&DAT_0000006e;
    pXVar2 = (X509 *)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x68,0x6e,"ocsp_srv.c",0xd9);
    goto LAB_005b17a8;
  }
  if ((flags & 1) == 0) {
    psVar6 = brsp->certs;
    if (psVar6 == (stack_st_X509 *)0x0) {
      psVar6 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
      brsp->certs = psVar6;
      if (psVar6 != (stack_st_X509 *)0x0) goto LAB_005b16ec;
    }
    else {
LAB_005b16ec:
      pXVar2 = signer;
      iVar4 = (*(code *)PTR_sk_push_006a80a8)(psVar6);
      if (iVar4 != 0) {
        pXVar8 = (X509 *)0x3;
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(&signer->references,1,3,"ocsp_srv.c",0xcc);
        for (pXVar10 = (X509 *)0x0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(certs),
            (int)pXVar10 < iVar4; pXVar10 = (X509 *)((int)&pXVar10->cert_info + 1)) {
          pXVar2 = pXVar10;
          pXVar5 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(certs);
          psVar6 = brsp->certs;
          if (psVar6 == (stack_st_X509 *)0x0) {
            psVar6 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
            brsp->certs = psVar6;
            if (psVar6 == (stack_st_X509 *)0x0) goto LAB_005b17a4;
          }
          pXVar2 = pXVar5;
          iVar4 = (*(code *)PTR_sk_push_006a80a8)(psVar6);
          if (iVar4 == 0) goto LAB_005b17a4;
          pXVar8 = (X509 *)0x3;
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pXVar5->references,1,3,"ocsp_srv.c",0xcc);
        }
        goto LAB_005b15b4;
      }
    }
  }
  else {
LAB_005b15b4:
    pOVar9 = brsp->tbsResponseData->responderId;
    if ((flags & 0x400) == 0) {
      pXVar2 = (X509 *)(*(code *)PTR_X509_get_subject_name_006a8000)(signer);
      iVar4 = (*(code *)PTR_X509_NAME_set_006aa048)(&pOVar9->value);
      if (iVar4 != 0) {
        pOVar9->type = 0;
LAB_005b1660:
        if ((flags & 0x800) == 0) {
          pXVar2 = (X509 *)0x0;
          iVar4 = (*(code *)PTR_X509_gmtime_adj_006a808c)(brsp->tbsResponseData->producedAt);
          if (iVar4 == 0) goto LAB_005b17a4;
        }
        pXVar8 = (X509 *)0x0;
        pXVar2 = (X509 *)brsp->signatureAlgorithm;
        iVar4 = (*(code *)PTR_ASN1_item_sign_006aa0a4)
                          (PTR_OCSP_RESPDATA_it_006aa3bc,pXVar2,0,brsp->signature,
                           brsp->tbsResponseData,key,dgst);
        uVar1 = (uint)(iVar4 != 0);
        goto LAB_005b17a8;
      }
    }
    else {
      pXVar10 = (X509 *)&stack0xffffffc0;
      pXVar2 = (X509 *)(*(code *)PTR_EVP_sha1_006a86c4)();
      pXVar8 = pXVar10;
      (*(code *)PTR_X509_pubkey_digest_006aa3b8)(signer,pXVar2,pXVar10,0);
      pXVar3 = (X509_NAME *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
      (pOVar9->value).byName = pXVar3;
      if (pXVar3 != (X509_NAME *)0x0) {
        pXVar8 = (X509 *)&DAT_00000014;
        iVar4 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(pXVar3,pXVar10,0x14);
        pXVar2 = pXVar10;
        if (iVar4 != 0) {
          pOVar9->type = 1;
          goto LAB_005b1660;
        }
      }
    }
  }
LAB_005b17a4:
  uVar1 = 0;
LAB_005b17a8:
  if (local_2c != *(char **)puVar11) {
    pcVar7 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar11 = (undefined *)((int)&pXVar8->cert_info + 2);
    (*(code *)PTR_BIO_printf_006a7f38)();
    (*(code *)PTR_BIO_printf_006a7f38)(pcVar7,"%*sHash Algorithm: ",puVar11,"");
    (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(pcVar7,pXVar2->cert_info->version);
    (*(code *)PTR_BIO_printf_006a7f38)(pcVar7,"\n%*sIssuer Name Hash: ",puVar11,"");
    (*(code *)PTR_i2a_ASN1_STRING_006aa1a4)(pcVar7,pXVar2->sig_alg,4);
    (*(code *)PTR_BIO_printf_006a7f38)(pcVar7,"\n%*sIssuer Key Hash: ",puVar11,"");
    (*(code *)PTR_i2a_ASN1_STRING_006aa1a4)(pcVar7,pXVar2->signature,4);
    (*(code *)PTR_BIO_printf_006a7f38)(pcVar7,"\n%*sSerial Number: ",puVar11,"");
    (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(pcVar7,pXVar2->valid);
    (*(code *)PTR_BIO_printf_006a7f38)(pcVar7,"\n");
    return 1;
  }
  return uVar1;
}

