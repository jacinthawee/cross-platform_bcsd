
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  X509_ALGOR **ppXVar1;
  int iVar2;
  EVP_PKEY *pkey;
  OCSP_CERTID **ppOVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  X509 *pXVar7;
  EVP_MD *pEVar8;
  stack_st_X509 *chain;
  int iVar9;
  uint uVar10;
  OCSP_CERTID *b;
  _STACK *p_Var11;
  _STACK *p_Var12;
  BUF_MEM *pBVar13;
  OCSP_RESPID *pOVar14;
  OCSP_CERTID *a;
  X509_STORE_CTX XStack_c8;
  uchar auStack_40 [20];
  int local_2c;
  
  pOVar14 = bs->tbsResponseData->responderId;
  local_2c = __TMC_END__;
  if (pOVar14->type != 0) {
    if (((pOVar14->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      pBVar13 = ((pOVar14->value).byName)->bytes;
      for (iVar9 = 0; iVar2 = sk_num(&certs->stack), iVar9 < iVar2; iVar9 = iVar9 + 1) {
        pXVar7 = (X509 *)sk_value(&certs->stack,iVar9);
        pEVar8 = EVP_sha1();
        X509_pubkey_digest(pXVar7,pEVar8,auStack_40,(uint *)0x0);
        iVar2 = memcmp(pBVar13,auStack_40,0x14);
        if (iVar2 == 0) goto LAB_000e3270;
      }
    }
LAB_000e3230:
    uVar10 = flags & 2;
    if (uVar10 == 0) {
      p_Var12 = (_STACK *)bs->certs;
      if (pOVar14->type == 0) {
        pXVar7 = X509_find_by_subject((stack_st_X509 *)p_Var12,(pOVar14->value).byName);
LAB_000e34a0:
        uVar10 = 1;
        if (pXVar7 != (X509 *)0x0) goto LAB_000e327e;
      }
      else if (((pOVar14->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
        pBVar13 = ((pOVar14->value).byName)->bytes;
        for (; iVar9 = sk_num(p_Var12), (int)uVar10 < iVar9; uVar10 = uVar10 + 1) {
          pXVar7 = (X509 *)sk_value(p_Var12,uVar10);
          pEVar8 = EVP_sha1();
          X509_pubkey_digest(pXVar7,pEVar8,auStack_40,(uint *)0x0);
          iVar9 = memcmp(pBVar13,auStack_40,0x14);
          if (iVar9 == 0) goto LAB_000e34a0;
        }
      }
    }
    uVar10 = 0;
    ERR_put_error(0x27,0x69,0x76,"ocsp_vfy.c",0x55);
    goto LAB_000e3250;
  }
  pXVar7 = X509_find_by_subject(certs,(pOVar14->value).byName);
LAB_000e3270:
  if (pXVar7 == (X509 *)0x0) goto LAB_000e3230;
  if ((flags & 0x200) == 0) {
    uVar10 = 2;
  }
  else {
    flags = flags | 0x10;
    uVar10 = 2;
  }
LAB_000e327e:
  if ((flags & 4) == 0) {
    pkey = X509_get_pubkey(pXVar7);
    if (pkey != (EVP_PKEY *)0x0) {
      uVar10 = ASN1_item_verify((ASN1_ITEM *)OCSP_RESPDATA_it,bs->signatureAlgorithm,bs->signature,
                                bs->tbsResponseData,pkey);
      EVP_PKEY_free(pkey);
      if (0 < (int)uVar10) goto LAB_000e3284;
    }
    ERR_put_error(0x27,0x69,0x75,"ocsp_vfy.c",0x65);
    goto LAB_000e3250;
  }
LAB_000e3284:
  chain = (stack_st_X509 *)(flags & 0x10);
  if (chain != (stack_st_X509 *)0x0) goto LAB_000e3250;
  if ((flags & 8) == 0) {
    chain = bs->certs;
  }
  iVar9 = X509_STORE_CTX_init(&XStack_c8,st,pXVar7,chain);
  if (iVar9 == 0) {
    uVar10 = 0xffffffff;
    ERR_put_error(0x27,0x69,0xb,"ocsp_vfy.c",0x73);
    goto LAB_000e3250;
  }
  X509_STORE_CTX_set_purpose(&XStack_c8,8);
  uVar10 = X509_verify_cert(&XStack_c8);
  p_Var12 = (_STACK *)X509_STORE_CTX_get1_chain(&XStack_c8);
  X509_STORE_CTX_cleanup(&XStack_c8);
  if ((int)uVar10 < 1) {
    iVar9 = X509_STORE_CTX_get_error(&XStack_c8);
    ERR_put_error(0x27,0x69,0x65,"ocsp_vfy.c",0x7e);
    pcVar6 = X509_verify_cert_error_string(iVar9);
    ERR_add_error_data(2,"Verify error:",pcVar6);
  }
  else if ((flags & 0x100) == 0) {
    p_Var11 = (_STACK *)bs->tbsResponseData->responses;
    iVar9 = sk_num(p_Var12);
    if (iVar9 < 1) {
      uVar10 = 0xffffffff;
      ERR_put_error(0x27,0x6c,0x69,"ocsp_vfy.c",0xe2);
    }
    else {
      iVar9 = sk_num(p_Var11);
      if (iVar9 < 1) {
        uVar10 = 0xffffffff;
        ERR_put_error(0x27,0x6b,0x6f,"ocsp_vfy.c",0x10d);
      }
      else {
        ppOVar3 = (OCSP_CERTID **)sk_value(p_Var11,0);
        a = *ppOVar3;
        if (iVar9 != 1) {
          iVar2 = 1;
          do {
            ppOVar3 = (OCSP_CERTID **)sk_value(p_Var11,iVar2);
            b = *ppOVar3;
            iVar4 = OCSP_id_issuer_cmp(a,b);
            if (iVar4 != 0) {
              ppXVar1 = &a->hashAlgorithm;
              a = (OCSP_CERTID *)0x0;
              iVar9 = OBJ_cmp(b->hashAlgorithm->algorithm,(*ppXVar1)->algorithm);
              if (iVar9 == 0) goto LAB_000e33d8;
              break;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 != iVar9);
        }
        pXVar7 = (X509 *)sk_value(p_Var12,0);
        iVar9 = sk_num(p_Var12);
        if (iVar9 < 2) {
LAB_000e33c6:
          uVar10 = ocsp_match_issuerid(pXVar7,a,p_Var11);
          if (uVar10 == 0) {
LAB_000e33d8:
            uVar10 = flags & 0x20;
            if (uVar10 == 0) {
              iVar9 = sk_num(p_Var12);
              pXVar7 = (X509 *)sk_value(p_Var12,iVar9 + -1);
              iVar9 = X509_check_trust(pXVar7,0xb4,0);
              if (iVar9 == 1) goto LAB_000e32d0;
              ERR_put_error(0x27,0x69,0x70,"ocsp_vfy.c",0x98);
            }
            else {
              uVar10 = 0;
            }
          }
        }
        else {
          pvVar5 = sk_value(p_Var12,1);
          uVar10 = ocsp_match_issuerid(pvVar5,a,p_Var11);
          if (-1 < (int)uVar10) {
            if (uVar10 == 0) goto LAB_000e33c6;
            X509_check_purpose(pXVar7,-1,0);
            if (((int)(pXVar7->ex_flags << 0x1d) < 0) && ((int)(pXVar7->ex_xkusage << 0x1a) < 0))
            goto LAB_000e32d0;
            ERR_put_error(0x27,0x6a,0x67,"ocsp_vfy.c",0x162);
            goto LAB_000e33d8;
          }
        }
      }
    }
  }
  else {
LAB_000e32d0:
    uVar10 = 1;
  }
  if (p_Var12 != (_STACK *)0x0) {
    sk_pop_free(p_Var12,X509_free + 1);
  }
LAB_000e3250:
  if (local_2c == __TMC_END__) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

