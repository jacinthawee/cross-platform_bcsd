
X509_PKEY * d2i_X509_PKEY(X509_PKEY **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  uchar *puVar3;
  int iVar4;
  undefined4 uVar5;
  X509_PKEY *pXVar6;
  ASN1_OCTET_STRING *pAVar7;
  EVP_CIPHER *pEVar8;
  ASN1_TYPE *pAVar9;
  X509_ALGOR *pXVar10;
  ASN1_STRING *pAVar11;
  X509_PKEY *pXVar12;
  long local_res8 [2];
  ASN1_const_CTX local_48;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar3 = *pp;
  local_48.error = 0x3a;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res8[0] = length;
  local_48.q = puVar3;
  local_48.pp = pp;
  if ((a == (X509_PKEY **)0x0) || (pXVar12 = *a, pXVar12 == (X509_PKEY *)0x0)) {
    pXVar12 = (X509_PKEY *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x34,"x_pkey.c",0x70);
    if (pXVar12 == (X509_PKEY *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xad,0x41,"x_pkey.c",0x70);
    }
    else {
      pXVar12->version = 0;
      pXVar10 = X509_ALGOR_new();
      pXVar12->enc_algor = pXVar10;
      if (pXVar10 != (X509_ALGOR *)0x0) {
        pAVar11 = ASN1_STRING_type_new(4);
        pXVar12->enc_pkey = pAVar11;
        puVar1 = PTR_memset_006aab00;
        if (pAVar11 != (ASN1_STRING *)0x0) {
          pXVar12->dec_pkey = (EVP_PKEY *)0x0;
          pXVar12->key_length = 0;
          pXVar12->key_data = (char *)0x0;
          pXVar12->key_free = 0;
          (pXVar12->cipher).cipher = (EVP_CIPHER *)0x0;
          (*(code *)puVar1)((pXVar12->cipher).iv,0,0x10);
          puVar3 = *pp;
          pXVar12->references = 1;
          goto LAB_00568520;
        }
      }
    }
    local_48.line = 0x4b;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9f,local_48.error,"x_pkey.c",0x4b);
    asn1_add_error(*pp,(int)local_48.q - (int)*pp);
    pXVar6 = (X509_PKEY *)0x0;
    goto LAB_005685d8;
  }
LAB_00568520:
  local_48.p = puVar3;
  if (local_res8[0] == 0) {
    local_48.max = (uchar *)0x0;
    iVar4 = asn1_GetSequence(&local_48,local_res8);
    if (iVar4 != 0) goto LAB_00568628;
LAB_00568550:
    uVar5 = 0x4e;
    local_48.line = 0x4e;
  }
  else {
    local_48.max = puVar3 + local_res8[0];
    iVar4 = asn1_GetSequence(&local_48,local_res8);
    if (iVar4 == 0) goto LAB_00568550;
LAB_00568628:
    local_48.q = local_48.p;
    pXVar10 = d2i_X509_ALGOR(&pXVar12->enc_algor,&local_48.p,local_48.slen);
    if (pXVar10 == (X509_ALGOR *)0x0) {
      uVar5 = 0x4f;
      local_48.line = 0x4f;
    }
    else {
      iVar4 = (int)local_48.p - (int)local_48.q;
      local_48.q = local_48.p;
      local_48.slen = local_48.slen - iVar4;
      pAVar7 = d2i_ASN1_OCTET_STRING(&pXVar12->enc_pkey,&local_48.p,local_48.slen);
      if (pAVar7 == (ASN1_OCTET_STRING *)0x0) {
        uVar5 = 0x50;
        local_48.line = 0x50;
      }
      else {
        local_48.slen = local_48.slen - ((int)local_48.p - (int)local_48.q);
        uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pXVar12->enc_algor->algorithm);
        uVar5 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar5);
        pEVar8 = (EVP_CIPHER *)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar5);
        (pXVar12->cipher).cipher = pEVar8;
        if (pEVar8 == (EVP_CIPHER *)0x0) {
          local_48.error = 0xa5;
          uVar5 = 0x57;
          local_48.line = 0x57;
        }
        else {
          pAVar9 = pXVar12->enc_algor->parameter;
          if (pAVar9->type == 4) {
            pAVar11 = (pAVar9->value).asn1_string;
            if (0x10 < pAVar11->length) {
              local_48.error = 0x87;
              uVar5 = 0x60;
              local_48.line = 0x60;
              goto LAB_00568560;
            }
            (*(code *)PTR_memcpy_006aabf4)((pXVar12->cipher).iv,pAVar11->data);
          }
          else {
            (*(code *)PTR_memset_006aab00)((pXVar12->cipher).iv,0,0x10);
          }
          iVar4 = asn1_const_Finish(&local_48);
          if (iVar4 != 0) {
            *pp = local_48.p;
            pXVar6 = pXVar12;
            if (a != (X509_PKEY **)0x0) {
              *a = pXVar12;
            }
            goto LAB_005685d8;
          }
          uVar5 = 0x68;
          local_48.line = 0x68;
        }
      }
    }
  }
LAB_00568560:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9f,local_48.error,"x_pkey.c",uVar5);
  asn1_add_error(*pp,(int)local_48.q - (int)*pp);
  if ((a == (X509_PKEY **)0x0) || (pXVar6 = (X509_PKEY *)0x0, pXVar12 != *a)) {
    iVar4 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                      (&pXVar12->references,0xffffffff,5,"x_pkey.c",0x85);
    if (iVar4 < 1) {
      if (pXVar12->enc_algor != (X509_ALGOR *)0x0) {
        X509_ALGOR_free(pXVar12->enc_algor);
      }
      if (pXVar12->enc_pkey != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(pXVar12->enc_pkey);
      }
      if (pXVar12->dec_pkey != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if ((pXVar12->key_data != (char *)0x0) && (pXVar12->key_free != 0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(pXVar12);
    }
    pXVar6 = (X509_PKEY *)0x0;
  }
LAB_005685d8:
  if (local_1c == *(int *)puVar2) {
    return pXVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pXVar12 = (X509_PKEY *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x34,"x_pkey.c",0x70);
  if (pXVar12 == (X509_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xad,0x41,"x_pkey.c",0x70);
  }
  else {
    pXVar12->version = 0;
    pXVar10 = X509_ALGOR_new();
    pXVar12->enc_algor = pXVar10;
    if (pXVar10 != (X509_ALGOR *)0x0) {
      pAVar11 = ASN1_STRING_type_new(4);
      pXVar12->enc_pkey = pAVar11;
      puVar2 = PTR_memset_006aab00;
      if (pAVar11 != (ASN1_STRING *)0x0) {
        pXVar12->dec_pkey = (EVP_PKEY *)0x0;
        pXVar12->key_length = 0;
        pXVar12->key_data = (char *)0x0;
        pXVar12->key_free = 0;
        (pXVar12->cipher).cipher = (EVP_CIPHER *)0x0;
        (*(code *)puVar2)((pXVar12->cipher).iv,0,0x10);
        pXVar12->references = 1;
        return pXVar12;
      }
    }
  }
  return (X509_PKEY *)0x0;
}

