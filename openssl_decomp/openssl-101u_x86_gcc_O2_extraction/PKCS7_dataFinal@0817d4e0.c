
int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  pkcs7_st *ppVar1;
  _STACK *p_Var2;
  PKCS7_SIGNED *pPVar3;
  int iVar4;
  PKCS7_SIGNER_INFO *si;
  EVP_MD *pEVar5;
  uchar *md;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar6;
  void *pvVar7;
  long lVar8;
  BIO *pBVar9;
  int in_GS_OFFSET;
  int iVar10;
  int local_a4;
  _STACK *local_9c;
  ASN1_STRING *local_90;
  EVP_MD_CTX *local_80;
  void *local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (p7 == (PKCS7 *)0x0) {
    iVar10 = 0x2f4;
    iVar4 = 0x8f;
LAB_0817db27:
    ERR_put_error(0x21,0x80,iVar4,"pk7_doit.c",iVar10);
    pBVar9 = (BIO *)0x0;
    goto LAB_0817d678;
  }
  if ((p7->d).ptr == (char *)0x0) {
    iVar10 = 0x2f9;
    iVar4 = 0x7a;
    goto LAB_0817db27;
  }
  EVP_MD_CTX_init(&local_78);
  iVar4 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar4) {
  case 0x15:
    local_90 = (p7->d).data;
    break;
  case 0x16:
    local_9c = (_STACK *)((p7->d).sign)->signer_info;
    ppVar1 = ((p7->d).sign)->contents;
    iVar4 = OBJ_obj2nid(ppVar1->type);
    if (iVar4 == 0x15) {
      local_90 = (ppVar1->d).data;
    }
    else {
      iVar4 = OBJ_obj2nid(ppVar1->type);
      if ((iVar4 - 0x15U < 6) || (pPVar3 = (ppVar1->d).sign, pPVar3 == (PKCS7_SIGNED *)0x0)) {
        local_90 = (ASN1_STRING *)0x0;
      }
      else {
        local_90 = (ASN1_STRING *)0x0;
        if (pPVar3->version == (ASN1_INTEGER *)0x4) {
          local_90 = (ASN1_STRING *)pPVar3->md_algs;
        }
      }
    }
    iVar4 = OBJ_obj2nid(((p7->d).sign)->contents->type);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free(local_90);
      local_90 = (ASN1_STRING *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    goto LAB_0817d57a;
  case 0x17:
    local_90 = (ASN1_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (local_90 == (ASN1_STRING *)0x0) {
      local_90 = ASN1_STRING_type_new(4);
      if (local_90 == (ASN1_STRING *)0x0) {
        iVar10 = 0x318;
LAB_0817dd38:
        iVar4 = 0x41;
        goto LAB_0817db04;
      }
      ((p7->d).enveloped)->enc_data->enc_data = local_90;
    }
    break;
  case 0x18:
    local_9c = (_STACK *)((p7->d).sign)->signer_info;
    local_90 = (ASN1_STRING *)((p7->d).sign)->contents->state;
    if (local_90 == (ASN1_STRING *)0x0) {
      local_90 = ASN1_STRING_type_new(4);
      if (local_90 == (ASN1_STRING *)0x0) {
        iVar10 = 0x30c;
        goto LAB_0817dd38;
      }
      ((p7->d).signed_and_enveloped)->enc_data->enc_data = local_90;
    }
LAB_0817d57a:
    if (local_9c != (_STACK *)0x0) {
      local_a4 = 0;
      while (iVar4 = sk_num(local_9c), local_a4 < iVar4) {
        si = (PKCS7_SIGNER_INFO *)sk_value(local_9c,local_a4);
        if (si->pkey == (EVP_PKEY *)0x0) {
LAB_0817d928:
          local_a4 = local_a4 + 1;
        }
        else {
          iVar4 = OBJ_obj2nid(si->digest_alg->algorithm);
          pBVar9 = bio;
          while( true ) {
            pBVar9 = BIO_find_type(pBVar9,0x208);
            if (pBVar9 == (BIO *)0x0) goto LAB_0817d649;
            BIO_ctrl(pBVar9,0x78,0,&local_80);
            if (local_80 == (EVP_MD_CTX *)0x0) goto LAB_0817da40;
            pEVar5 = EVP_MD_CTX_md(local_80);
            iVar10 = EVP_MD_type(pEVar5);
            if (iVar4 == iVar10) break;
            pBVar9 = BIO_next(pBVar9);
          }
          iVar4 = EVP_MD_CTX_copy_ex(&local_78,local_80);
          if (iVar4 == 0) goto LAB_0817d664;
          iVar4 = sk_num((_STACK *)si->auth_attr);
          if (iVar4 < 1) {
            local_7c = (void *)EVP_PKEY_size(si->pkey);
            md = (uchar *)CRYPTO_malloc((int)local_7c,"pk7_doit.c",0x35a);
            if (md != (uchar *)0x0) {
              iVar4 = EVP_SignFinal(&local_78,md,(uint *)&local_7c,si->pkey);
              if (iVar4 != 0) {
                ASN1_STRING_set0(si->enc_digest,md,(int)local_7c);
                goto LAB_0817d928;
              }
              ERR_put_error(0x21,0x80,6,"pk7_doit.c",0x35f);
            }
            goto LAB_0817d664;
          }
          p_Var2 = (_STACK *)si->auth_attr;
          b = OBJ_nid2obj(0x34);
          if ((b != (ASN1_OBJECT *)0x0) && (p_Var2 != (_STACK *)0x0)) {
            for (iVar4 = 0; iVar10 = sk_num(p_Var2), iVar4 < iVar10; iVar4 = iVar4 + 1) {
              ppAVar6 = (ASN1_OBJECT **)sk_value(p_Var2,iVar4);
              iVar10 = OBJ_cmp(*ppAVar6,b);
              if (iVar10 == 0) {
                if (((ppAVar6[1] == (ASN1_OBJECT *)0x0) &&
                    (iVar4 = sk_num((_STACK *)ppAVar6[2]), iVar4 != 0)) &&
                   (pvVar7 = sk_value((_STACK *)ppAVar6[2],0), pvVar7 != (void *)0x0))
                goto LAB_0817d9e1;
                break;
              }
            }
          }
          iVar4 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0);
          if (iVar4 == 0) {
            iVar4 = 0x2d2;
LAB_0817dad0:
            ERR_put_error(0x21,0x88,0x41,"pk7_doit.c",iVar4);
            goto LAB_0817d664;
          }
LAB_0817d9e1:
          iVar4 = EVP_DigestFinal_ex(&local_78,local_60,(uint *)&local_7c);
          if (iVar4 == 0) {
            ERR_put_error(0x21,0x88,6,"pk7_doit.c",0x2d9);
            goto LAB_0817d664;
          }
          iVar4 = PKCS7_add1_attrib_digest(si,local_60,(int)local_7c);
          if (iVar4 == 0) {
            iVar4 = 0x2dd;
            goto LAB_0817dad0;
          }
          iVar4 = PKCS7_SIGNER_INFO_sign(si);
          if (iVar4 == 0) goto LAB_0817d664;
          local_a4 = local_a4 + 1;
        }
      }
    }
    break;
  case 0x19:
    ppVar1 = ((p7->d).digest)->contents;
    iVar4 = OBJ_obj2nid(ppVar1->type);
    if (iVar4 == 0x15) {
      local_90 = (ppVar1->d).data;
    }
    else {
      iVar4 = OBJ_obj2nid(ppVar1->type);
      if ((iVar4 - 0x15U < 6) || (pPVar3 = (ppVar1->d).sign, pPVar3 == (PKCS7_SIGNED *)0x0)) {
        local_90 = (ASN1_STRING *)0x0;
      }
      else {
        local_90 = (ASN1_STRING *)0x0;
        if (pPVar3->version == (ASN1_INTEGER *)0x4) {
          local_90 = (ASN1_STRING *)pPVar3->md_algs;
        }
      }
    }
    iVar4 = OBJ_obj2nid(((p7->d).digest)->contents->type);
    if ((iVar4 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free(local_90);
      local_90 = (ASN1_STRING *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar4 = OBJ_obj2nid(((p7->d).digest)->md->algorithm);
    pBVar9 = bio;
    while (pBVar9 = BIO_find_type(pBVar9,0x208), pBVar9 != (BIO *)0x0) {
      BIO_ctrl(pBVar9,0x78,0,&local_80);
      if (local_80 == (EVP_MD_CTX *)0x0) goto LAB_0817da40;
      pEVar5 = EVP_MD_CTX_md(local_80);
      iVar10 = EVP_MD_type(pEVar5);
      if (iVar4 == iVar10) {
        iVar4 = EVP_DigestFinal_ex(local_80,local_60,(uint *)&local_7c);
        if (iVar4 == 0) goto LAB_0817d664;
        ASN1_STRING_set((ASN1_STRING *)((p7->d).sign)->crl,local_60,(int)local_7c);
        goto LAB_0817d78b;
      }
      pBVar9 = BIO_next(pBVar9);
    }
LAB_0817d649:
    ERR_put_error(0x21,0x7f,0x6c,"pk7_doit.c",699);
    goto LAB_0817d664;
  default:
    iVar10 = 0x334;
    iVar4 = 0x70;
LAB_0817db04:
    ERR_put_error(0x21,0x80,iVar4,"pk7_doit.c",iVar10);
    goto LAB_0817d664;
  }
LAB_0817d78b:
  iVar4 = OBJ_obj2nid(p7->type);
  if ((iVar4 == 0x16) && (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 != 0)) {
LAB_0817d7c0:
    pBVar9 = (BIO *)0x1;
  }
  else {
    if (local_90 != (ASN1_STRING *)0x0) {
      if ((*(byte *)&local_90->flags & 0x10) == 0) {
        pBVar9 = BIO_find_type(bio,0x401);
        if (pBVar9 == (BIO *)0x0) {
          ERR_put_error(0x21,0x80,0x6b,"pk7_doit.c",0x37c);
          goto LAB_0817d666;
        }
        lVar8 = BIO_ctrl(pBVar9,3,0,&local_7c);
        BIO_set_flags(pBVar9,0x200);
        BIO_ctrl(pBVar9,0x82,0,(void *)0x0);
        ASN1_STRING_set0(local_90,local_7c,lVar8);
      }
      goto LAB_0817d7c0;
    }
LAB_0817d664:
    pBVar9 = (BIO *)0x0;
  }
LAB_0817d666:
  EVP_MD_CTX_cleanup(&local_78);
LAB_0817d678:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)pBVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0817da40:
  ERR_put_error(0x21,0x7f,0x44,"pk7_doit.c",0x2c0);
  goto LAB_0817d664;
}

