
X509_PKEY * d2i_X509_PKEY(X509_PKEY **a,uchar **pp,long length)

{
  ASN1_TYPE *pAVar1;
  undefined4 *puVar2;
  uchar *puVar3;
  int iVar4;
  X509_PKEY *ptr;
  X509_ALGOR *pXVar5;
  ASN1_OCTET_STRING *pAVar6;
  char *name;
  EVP_CIPHER *pEVar7;
  ASN1_STRING *pAVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int in_GS_OFFSET;
  ASN1_const_CTX local_4c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c.error = 0x3a;
  puVar3 = *pp;
  local_4c.pp = pp;
  local_4c.q = puVar3;
  if ((a == (X509_PKEY **)0x0) || (ptr = *a, ptr == (X509_PKEY *)0x0)) {
    ptr = (X509_PKEY *)CRYPTO_malloc(0x34,"x_pkey.c",0x70);
    if (ptr == (X509_PKEY *)0x0) {
      ERR_put_error(0xd,0xad,0x41,"x_pkey.c",0x70);
    }
    else {
      ptr->version = 0;
      pXVar5 = X509_ALGOR_new();
      ptr->enc_algor = pXVar5;
      if (pXVar5 != (X509_ALGOR *)0x0) {
        pAVar8 = ASN1_STRING_type_new(4);
        ptr->enc_pkey = pAVar8;
        if (pAVar8 != (ASN1_STRING *)0x0) {
          ptr->dec_pkey = (EVP_PKEY *)0x0;
          ptr->key_data = (char *)0x0;
          (ptr->cipher).cipher = (EVP_CIPHER *)0x0;
          *(undefined4 *)(ptr->cipher).iv = 0;
          *(undefined4 *)((ptr->cipher).iv + 4) = 0;
          *(undefined4 *)((ptr->cipher).iv + 8) = 0;
          *(undefined4 *)((ptr->cipher).iv + 0xc) = 0;
          ptr->key_length = 0;
          ptr->key_free = 0;
          ptr->references = 1;
          puVar3 = *pp;
          goto LAB_081503ff;
        }
      }
    }
    local_4c.line = 0x4b;
    ERR_put_error(0xd,0x9f,local_4c.error,"x_pkey.c",0x4b);
    asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
    ptr = (X509_PKEY *)0x0;
    goto LAB_0815049b;
  }
LAB_081503ff:
  local_4c.max = puVar3 + length;
  if (length == 0) {
    local_4c.max = (uchar *)0x0;
  }
  local_4c.p = puVar3;
  iVar4 = asn1_GetSequence(&local_4c,&length);
  if (iVar4 == 0) {
    local_4c.line = 0x4e;
    iVar4 = 0x4e;
  }
  else {
    local_4c.q = local_4c.p;
    pXVar5 = d2i_X509_ALGOR(&ptr->enc_algor,&local_4c.p,local_4c.slen);
    if (pXVar5 == (X509_ALGOR *)0x0) {
      local_4c.line = 0x4f;
      iVar4 = 0x4f;
    }
    else {
      iVar4 = (int)local_4c.p - (int)local_4c.q;
      local_4c.q = local_4c.p;
      local_4c.slen = local_4c.slen - iVar4;
      pAVar6 = d2i_ASN1_OCTET_STRING(&ptr->enc_pkey,&local_4c.p,local_4c.slen);
      if (pAVar6 == (ASN1_OCTET_STRING *)0x0) {
        local_4c.line = 0x50;
        iVar4 = 0x50;
      }
      else {
        local_4c.slen = local_4c.slen - ((int)local_4c.p - (int)local_4c.q);
        iVar4 = OBJ_obj2nid(ptr->enc_algor->algorithm);
        name = OBJ_nid2ln(iVar4);
        pEVar7 = EVP_get_cipherbyname(name);
        (ptr->cipher).cipher = pEVar7;
        if (pEVar7 == (EVP_CIPHER *)0x0) {
          local_4c.error = 0xa5;
          local_4c.line = 0x57;
          iVar4 = 0x57;
        }
        else {
          pAVar1 = ptr->enc_algor->parameter;
          if (pAVar1->type == 4) {
            pAVar8 = (pAVar1->value).asn1_string;
            uVar11 = pAVar8->length;
            if (0x10 < (int)uVar11) {
              local_4c.error = 0x87;
              local_4c.line = 0x60;
              iVar4 = 0x60;
              goto LAB_08150445;
            }
            puVar2 = (undefined4 *)pAVar8->data;
            puVar3 = (ptr->cipher).iv;
            if (uVar11 < 4) {
              if ((uVar11 != 0) && (*puVar3 = *(uchar *)puVar2, (uVar11 & 2) != 0)) {
                *(undefined2 *)((ptr->cipher).iv + (uVar11 - 2)) =
                     *(undefined2 *)((int)puVar2 + (uVar11 - 2));
              }
            }
            else {
              *(undefined4 *)(ptr->cipher).iv = *puVar2;
              *(undefined4 *)((ptr->cipher).iv + (uVar11 - 4)) =
                   *(undefined4 *)((int)puVar2 + (uVar11 - 4));
              uVar9 = (uint)((ptr->cipher).iv + 4) & 0xfffffffc;
              iVar4 = (int)puVar3 - uVar9;
              uVar11 = iVar4 + uVar11 & 0xfffffffc;
              if (3 < uVar11) {
                uVar10 = 0;
                do {
                  *(undefined4 *)(uVar9 + uVar10) = *(undefined4 *)((int)puVar2 + (uVar10 - iVar4));
                  uVar10 = uVar10 + 4;
                } while (uVar10 < uVar11);
              }
            }
          }
          else {
            *(undefined4 *)(ptr->cipher).iv = 0;
            *(undefined4 *)((ptr->cipher).iv + 4) = 0;
            *(undefined4 *)((ptr->cipher).iv + 8) = 0;
            *(undefined4 *)((ptr->cipher).iv + 0xc) = 0;
          }
          iVar4 = asn1_const_Finish(&local_4c);
          if (iVar4 != 0) {
            *pp = local_4c.p;
            if (a != (X509_PKEY **)0x0) {
              *a = ptr;
            }
            goto LAB_0815049b;
          }
          local_4c.line = 0x68;
          iVar4 = 0x68;
        }
      }
    }
  }
LAB_08150445:
  ERR_put_error(0xd,0x9f,local_4c.error,"x_pkey.c",iVar4);
  asn1_add_error(*pp,(int)local_4c.q - (int)*pp);
  if (((a == (X509_PKEY **)0x0) || (ptr != *a)) &&
     (iVar4 = CRYPTO_add_lock(&ptr->references,-1,5,"x_pkey.c",0x85), iVar4 < 1)) {
    if (ptr->enc_algor != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(ptr->enc_algor);
    }
    if (ptr->enc_pkey != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(ptr->enc_pkey);
    }
    if (ptr->dec_pkey != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(ptr->dec_pkey);
    }
    if ((ptr->key_data != (char *)0x0) && (ptr->key_free != 0)) {
      CRYPTO_free(ptr->key_data);
    }
    CRYPTO_free(ptr);
  }
  ptr = (X509_PKEY *)0x0;
LAB_0815049b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ptr;
}

