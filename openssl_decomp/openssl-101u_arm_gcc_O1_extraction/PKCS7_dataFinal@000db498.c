
int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  int iVar1;
  int iVar2;
  PKCS7_SIGNER_INFO *si;
  int iVar3;
  uchar *md;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar4;
  void *pvVar5;
  long lVar6;
  EVP_MD *pEVar7;
  BIO *pBVar8;
  uint uVar9;
  pkcs7_st *ppVar10;
  _STACK *p_Var11;
  _STACK *p_Var12;
  BIO *local_94;
  EVP_MD_CTX *local_8c;
  void *local_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x80,0x8f,"pk7_doit.c",0x2f4);
    goto LAB_000db55e;
  }
  pBVar8 = (BIO *)(p7->d).ptr;
  if (pBVar8 == (BIO *)0x0) {
    ERR_put_error(0x21,0x80,0x7a,"pk7_doit.c",0x2f9);
    p7 = (PKCS7 *)pBVar8;
    goto LAB_000db55e;
  }
  EVP_MD_CTX_init(&EStack_84);
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar1) {
  case 0x15:
    local_94 = (BIO *)(p7->d).data;
    break;
  case 0x16:
    ppVar10 = ((p7->d).sign)->contents;
    p_Var12 = (_STACK *)((p7->d).sign)->signer_info;
    iVar2 = OBJ_obj2nid(ppVar10->type);
    if (iVar2 == 0x15) {
      local_94 = (BIO *)(ppVar10->d).data;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar10->type);
      if (iVar2 - 0x15U < 6) {
        local_94 = (BIO *)0x0;
      }
      else {
        local_94 = (BIO *)(ppVar10->d).data;
        if (local_94 != (BIO *)0x0) {
          if (local_94->method == (BIO_METHOD *)0x4) {
            local_94 = (BIO *)local_94->callback;
          }
          else {
            local_94 = (BIO *)0x0;
          }
        }
      }
    }
    iVar2 = OBJ_obj2nid(((p7->d).sign)->contents->type);
    if ((iVar2 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free((ASN1_STRING *)local_94);
      local_94 = (BIO *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    goto LAB_000db5ae;
  case 0x17:
    local_94 = (BIO *)(((p7->d).sign)->cert->stack).sorted;
    if (local_94 == (BIO *)0x0) {
      local_94 = (BIO *)ASN1_STRING_type_new(4);
      if (local_94 == (BIO *)0x0) {
        iVar2 = 0x318;
LAB_000db97c:
        ERR_put_error(0x21,0x80,0x41,"pk7_doit.c",iVar2);
        goto LAB_000db556;
      }
      ((p7->d).enveloped)->enc_data->enc_data = (ASN1_OCTET_STRING *)local_94;
    }
    break;
  case 0x18:
    p_Var12 = (_STACK *)((p7->d).sign)->signer_info;
    local_94 = (BIO *)((p7->d).sign)->contents->state;
    if (local_94 == (BIO *)0x0) {
      local_94 = (BIO *)ASN1_STRING_type_new(4);
      iVar2 = 0x30c;
      if (local_94 == (BIO *)0x0) goto LAB_000db97c;
      ((p7->d).signed_and_enveloped)->enc_data->enc_data = (ASN1_OCTET_STRING *)local_94;
    }
LAB_000db5ae:
    if (p_Var12 == (_STACK *)0x0) break;
    iVar1 = 0;
    while (iVar2 = sk_num(p_Var12), iVar1 < iVar2) {
      si = (PKCS7_SIGNER_INFO *)sk_value(p_Var12,iVar1);
      if (si->pkey == (EVP_PKEY *)0x0) {
LAB_000db6cc:
        iVar1 = iVar1 + 1;
      }
      else {
        iVar2 = OBJ_obj2nid(si->digest_alg->algorithm);
        pBVar8 = bio;
        while( true ) {
          pBVar8 = BIO_find_type(pBVar8,0x208);
          if (pBVar8 == (BIO *)0x0) goto LAB_000db610;
          BIO_ctrl(pBVar8,0x78,0,&local_8c);
          if (local_8c == (EVP_MD_CTX *)0x0) goto LAB_000db6d2;
          pEVar7 = EVP_MD_CTX_md(local_8c);
          iVar3 = EVP_MD_type(pEVar7);
          if (iVar2 == iVar3) break;
          pBVar8 = BIO_next(pBVar8);
        }
        iVar2 = EVP_MD_CTX_copy_ex(&EStack_84,local_8c);
        if (iVar2 == 0) goto LAB_000db628;
        iVar2 = sk_num((_STACK *)si->auth_attr);
        if (iVar2 < 1) {
          local_88 = (void *)EVP_PKEY_size(si->pkey);
          md = (uchar *)CRYPTO_malloc((int)local_88,"pk7_doit.c",0x35a);
          if (md != (uchar *)0x0) {
            iVar2 = EVP_SignFinal(&EStack_84,md,(uint *)&local_88,si->pkey);
            if (iVar2 != 0) {
              ASN1_STRING_set0(si->enc_digest,md,(int)local_88);
              goto LAB_000db6cc;
            }
            ERR_put_error(0x21,0x80,6,"pk7_doit.c",0x35f);
          }
          goto LAB_000db628;
        }
        p_Var11 = (_STACK *)si->auth_attr;
        b = OBJ_nid2obj(0x34);
        uVar9 = (uint)(p_Var11 == (_STACK *)0x0 || b == (ASN1_OBJECT *)0x0);
        if (p_Var11 != (_STACK *)0x0 && b != (ASN1_OBJECT *)0x0) {
          for (; iVar2 = sk_num(p_Var11), (int)uVar9 < iVar2; uVar9 = uVar9 + 1) {
            ppAVar4 = (ASN1_OBJECT **)sk_value(p_Var11,uVar9);
            iVar2 = OBJ_cmp(*ppAVar4,b);
            if (iVar2 == 0) {
              if (((ppAVar4[1] == (ASN1_OBJECT *)0x0) &&
                  (iVar2 = sk_num((_STACK *)ppAVar4[2]), iVar2 != 0)) &&
                 (pvVar5 = sk_value((_STACK *)ppAVar4[2],0), pvVar5 != (void *)0x0))
              goto LAB_000db748;
              break;
            }
          }
        }
        iVar2 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0);
        if (iVar2 == 0) {
          iVar1 = 0x2d2;
LAB_000db7b8:
          ERR_put_error(0x21,0x88,0x41,"pk7_doit.c",iVar1);
          goto LAB_000db628;
        }
LAB_000db748:
        iVar2 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,(uint *)&local_88);
        if (iVar2 == 0) {
          ERR_put_error(0x21,0x88,6,"pk7_doit.c",0x2d9);
          goto LAB_000db628;
        }
        iVar2 = PKCS7_add1_attrib_digest(si,auStack_6c,(int)local_88);
        if (iVar2 == 0) {
          iVar1 = 0x2dd;
          goto LAB_000db7b8;
        }
        iVar2 = PKCS7_SIGNER_INFO_sign(si);
        if (iVar2 == 0) goto LAB_000db628;
        iVar1 = iVar1 + 1;
      }
    }
    goto LAB_000db534;
  case 0x19:
    ppVar10 = ((p7->d).digest)->contents;
    iVar2 = OBJ_obj2nid(ppVar10->type);
    if (iVar2 == 0x15) {
      local_94 = (BIO *)(ppVar10->d).data;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar10->type);
      if (iVar2 - 0x15U < 6) {
        local_94 = (BIO *)0x0;
      }
      else {
        local_94 = (BIO *)(ppVar10->d).data;
        if (local_94 != (BIO *)0x0) {
          if (local_94->method == (BIO_METHOD *)0x4) {
            local_94 = (BIO *)local_94->callback;
          }
          else {
            local_94 = (BIO *)0x0;
          }
        }
      }
    }
    iVar2 = OBJ_obj2nid(((p7->d).digest)->contents->type);
    if ((iVar2 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free((ASN1_STRING *)local_94);
      local_94 = (BIO *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    break;
  default:
    ERR_put_error(0x21,0x80,0x70,"pk7_doit.c",0x334);
    local_94 = (BIO *)0x0;
    goto LAB_000db556;
  }
  if (iVar1 == 0x19) {
    iVar1 = OBJ_obj2nid(((p7->d).digest)->md->algorithm);
    pBVar8 = bio;
    while (pBVar8 = BIO_find_type(pBVar8,0x208), pBVar8 != (BIO *)0x0) {
      BIO_ctrl(pBVar8,0x78,0,&local_8c);
      if (local_8c == (EVP_MD_CTX *)0x0) goto LAB_000db6d2;
      pEVar7 = EVP_MD_CTX_md(local_8c);
      iVar2 = EVP_MD_type(pEVar7);
      if (iVar1 == iVar2) {
        iVar1 = EVP_DigestFinal_ex(local_8c,auStack_6c,(uint *)&local_88);
        if (iVar1 == 0) goto LAB_000db628;
        ASN1_STRING_set((ASN1_STRING *)((p7->d).sign)->crl,auStack_6c,(int)local_88);
        goto LAB_000db534;
      }
      pBVar8 = BIO_next(pBVar8);
    }
LAB_000db610:
    ERR_put_error(0x21,0x7f,0x6c,"pk7_doit.c",699);
LAB_000db628:
    local_94 = (BIO *)0x0;
  }
  else {
LAB_000db534:
    iVar1 = OBJ_obj2nid(p7->type);
    if ((iVar1 == 0x16) && (lVar6 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar6 != 0)) {
LAB_000db552:
      local_94 = (BIO *)0x1;
    }
    else {
      if (local_94 == (BIO *)0x0) goto LAB_000db628;
      if ((local_94->init & 0x10U) != 0) goto LAB_000db552;
      pBVar8 = BIO_find_type(bio,0x401);
      if (pBVar8 == (BIO *)0x0) {
        ERR_put_error(0x21,0x80,0x6b,"pk7_doit.c",0x37c);
        local_94 = pBVar8;
      }
      else {
        lVar6 = BIO_ctrl(pBVar8,3,0,&local_88);
        BIO_set_flags(pBVar8,0x200);
        BIO_ctrl(pBVar8,0x82,0,(void *)0x0);
        ASN1_STRING_set0((ASN1_STRING *)local_94,local_88,lVar6);
        local_94 = (BIO *)0x1;
      }
    }
  }
LAB_000db556:
  EVP_MD_CTX_cleanup(&EStack_84);
  p7 = (PKCS7 *)local_94;
LAB_000db55e:
  if (local_2c == __stack_chk_guard) {
    return (int)p7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_000db6d2:
  ERR_put_error(0x21,0x7f,0x44,"pk7_doit.c",0x2c0);
  goto LAB_000db628;
}

