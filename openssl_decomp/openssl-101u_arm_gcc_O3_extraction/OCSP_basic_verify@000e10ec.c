
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  int iVar1;
  _STACK *st_00;
  EVP_PKEY *pkey;
  OCSP_CERTID **ppOVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  X509 *pXVar6;
  EVP_MD *pEVar7;
  _STACK *p_Var8;
  int iVar9;
  uint uVar10;
  OCSP_CERTID *b;
  BUF_MEM *pBVar11;
  uint uVar12;
  _STACK *p_Var13;
  OCSP_RESPID *pOVar14;
  OCSP_CERTID *local_d0;
  X509_STORE_CTX XStack_c8;
  uchar auStack_40 [20];
  int local_2c;
  
  pOVar14 = bs->tbsResponseData->responderId;
  local_2c = __stack_chk_guard;
  if (pOVar14->type != 0) {
    if (((pOVar14->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      pBVar11 = ((pOVar14->value).byName)->bytes;
      for (iVar9 = 0; iVar1 = sk_num(&certs->stack), iVar9 < iVar1; iVar9 = iVar9 + 1) {
        pXVar6 = (X509 *)sk_value(&certs->stack,iVar9);
        pEVar7 = EVP_sha1();
        X509_pubkey_digest(pXVar6,pEVar7,auStack_40,(uint *)0x0);
        iVar1 = memcmp(pBVar11,auStack_40,0x14);
        if (iVar1 == 0) goto LAB_000e11aa;
      }
    }
LAB_000e1158:
    uVar12 = flags & 2;
    if (uVar12 == 0) {
      p_Var13 = (_STACK *)bs->certs;
      if (pOVar14->type == 0) {
        pXVar6 = X509_find_by_subject((stack_st_X509 *)p_Var13,(pOVar14->value).byName);
LAB_000e1444:
        uVar12 = 1;
        if (pXVar6 != (X509 *)0x0) goto LAB_000e11ba;
      }
      else if (((pOVar14->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
        pBVar11 = ((pOVar14->value).byName)->bytes;
        for (; iVar9 = sk_num(p_Var13), (int)uVar12 < iVar9; uVar12 = uVar12 + 1) {
          pXVar6 = (X509 *)sk_value(p_Var13,uVar12);
          pEVar7 = EVP_sha1();
          X509_pubkey_digest(pXVar6,pEVar7,auStack_40,(uint *)0x0);
          iVar9 = memcmp(pBVar11,auStack_40,0x14);
          if (iVar9 == 0) goto LAB_000e1444;
        }
      }
    }
    uVar12 = 0;
    ERR_put_error(0x27,0x69,0x76,"ocsp_vfy.c",0x5c);
    p_Var13 = (_STACK *)0x0;
    goto LAB_000e117c;
  }
  pXVar6 = X509_find_by_subject(certs,(pOVar14->value).byName);
LAB_000e11aa:
  if (pXVar6 == (X509 *)0x0) goto LAB_000e1158;
  if ((flags & 0x200) == 0) {
    uVar12 = 2;
  }
  else {
    flags = flags | 0x10;
    uVar12 = 2;
  }
LAB_000e11ba:
  if ((flags & 4) == 0) {
    pkey = X509_get_pubkey(pXVar6);
    if (pkey != (EVP_PKEY *)0x0) {
      uVar12 = ASN1_item_verify((ASN1_ITEM *)OCSP_RESPDATA_it,bs->signatureAlgorithm,bs->signature,
                                bs->tbsResponseData,pkey);
      EVP_PKEY_free(pkey);
      if (0 < (int)uVar12) goto LAB_000e11c0;
    }
    p_Var13 = (_STACK *)0x0;
    ERR_put_error(0x27,0x69,0x75,"ocsp_vfy.c",0x69);
    goto LAB_000e117c;
  }
LAB_000e11c0:
  p_Var13 = (_STACK *)(flags & 0x10);
  if (p_Var13 != (_STACK *)0x0) {
    p_Var13 = (_STACK *)0x0;
    goto LAB_000e117c;
  }
  uVar10 = flags & 8;
  if (((uVar10 == 0) && (p_Var13 = (_STACK *)bs->certs, p_Var13 != (_STACK *)0x0)) &&
     (certs != (stack_st_X509 *)0x0)) {
    p_Var13 = sk_dup(p_Var13);
    for (; iVar9 = sk_num(&certs->stack), (int)uVar10 < iVar9; uVar10 = uVar10 + 1) {
      pvVar4 = sk_value(&certs->stack,uVar10);
      iVar9 = sk_push(p_Var13,pvVar4);
      if (iVar9 == 0) {
        ERR_put_error(0x27,0x69,0x41,"ocsp_vfy.c",0x75);
        goto LAB_000e117c;
      }
    }
  }
  iVar9 = X509_STORE_CTX_init(&XStack_c8,st,pXVar6,(stack_st_X509 *)p_Var13);
  if (iVar9 == 0) {
    uVar12 = 0xffffffff;
    ERR_put_error(0x27,0x69,0xb,"ocsp_vfy.c",0x7f);
    goto LAB_000e117c;
  }
  X509_STORE_CTX_set_purpose(&XStack_c8,8);
  uVar12 = X509_verify_cert(&XStack_c8);
  st_00 = (_STACK *)X509_STORE_CTX_get1_chain(&XStack_c8);
  X509_STORE_CTX_cleanup(&XStack_c8);
  if ((int)uVar12 < 1) {
    iVar9 = X509_STORE_CTX_get_error(&XStack_c8);
    ERR_put_error(0x27,0x69,0x65,"ocsp_vfy.c",0x8a);
    pcVar5 = X509_verify_cert_error_string(iVar9);
    ERR_add_error_data(2,"Verify error:",pcVar5);
  }
  else if ((flags & 0x100) == 0) {
    p_Var8 = (_STACK *)bs->tbsResponseData->responses;
    iVar9 = sk_num(st_00);
    if (iVar9 < 1) {
      uVar12 = 0xffffffff;
      ERR_put_error(0x27,0x6c,0x69,"ocsp_vfy.c",0xed);
    }
    else {
      iVar9 = sk_num(p_Var8);
      if (iVar9 < 1) {
        uVar12 = 0xffffffff;
        ERR_put_error(0x27,0x6b,0x6f,"ocsp_vfy.c",0x11a);
      }
      else {
        ppOVar2 = (OCSP_CERTID **)sk_value(p_Var8,0);
        local_d0 = *ppOVar2;
        if (iVar9 != 1) {
          iVar1 = 1;
          do {
            ppOVar2 = (OCSP_CERTID **)sk_value(p_Var8,iVar1);
            b = *ppOVar2;
            iVar3 = OCSP_id_issuer_cmp(local_d0,b);
            if (iVar3 != 0) {
              iVar9 = OBJ_cmp(b->hashAlgorithm->algorithm,local_d0->hashAlgorithm->algorithm);
              if (iVar9 == 0) goto LAB_000e135e;
              local_d0 = (OCSP_CERTID *)0x0;
              break;
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 != iVar9);
        }
        pXVar6 = (X509 *)sk_value(st_00,0);
        iVar9 = sk_num(st_00);
        if (iVar9 < 2) {
LAB_000e134c:
          uVar12 = ocsp_match_issuerid(pXVar6,local_d0,p_Var8);
          if (uVar12 == 0) {
LAB_000e135e:
            uVar12 = flags & 0x20;
            if (uVar12 == 0) {
              iVar9 = sk_num(st_00);
              pXVar6 = (X509 *)sk_value(st_00,iVar9 + -1);
              iVar9 = X509_check_trust(pXVar6,0xb4,0);
              if (iVar9 == 1) goto LAB_000e1242;
              ERR_put_error(0x27,0x69,0x70,"ocsp_vfy.c",0xa6);
            }
            else {
              uVar12 = 0;
            }
          }
        }
        else {
          pvVar4 = sk_value(st_00,1);
          uVar12 = ocsp_match_issuerid(pvVar4,local_d0,p_Var8);
          if (-1 < (int)uVar12) {
            if (uVar12 == 0) goto LAB_000e134c;
            X509_check_purpose(pXVar6,-1,0);
            if (((int)(pXVar6->ex_flags << 0x1d) < 0) && ((int)(pXVar6->ex_xkusage << 0x1a) < 0))
            goto LAB_000e1242;
            ERR_put_error(0x27,0x6a,0x67,"ocsp_vfy.c",0x168);
            goto LAB_000e135e;
          }
        }
      }
    }
  }
  else {
LAB_000e1242:
    uVar12 = 1;
  }
  if (st_00 != (_STACK *)0x0) {
    sk_pop_free(st_00,X509_free + 1);
  }
LAB_000e117c:
  if ((bs->certs != (stack_st_X509 *)0x0) && (certs != (stack_st_X509 *)0x0)) {
    sk_free(p_Var13);
  }
  if (local_2c == __stack_chk_guard) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

