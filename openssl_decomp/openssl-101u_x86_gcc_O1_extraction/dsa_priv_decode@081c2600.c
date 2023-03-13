
int dsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  ASN1_INTEGER *ai;
  int *piVar2;
  int *piVar3;
  BIGNUM *pBVar4;
  DSA *r;
  BN_CTX *ctx;
  _STACK *st;
  int in_GS_OFFSET;
  int iVar5;
  uchar *local_38;
  long local_34;
  int local_30;
  long *local_2c;
  X509_ALGOR *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_38,&local_34,&local_28,param_2);
  if (iVar1 == 0) goto LAB_081c2639;
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_30,&local_2c,local_28);
  if (*local_38 == '0') {
    st = (_STACK *)d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_38,local_34);
    if (st == (_STACK *)0x0) {
      ai = (ASN1_INTEGER *)0x0;
    }
    else {
      ai = (ASN1_INTEGER *)0x0;
      iVar1 = sk_num(st);
      if (iVar1 == 2) {
        piVar2 = (int *)sk_value(st,0);
        piVar3 = (int *)sk_value(st,1);
        if (*piVar2 == 0x10) {
          param_2->broken = 2;
          local_2c = (long *)piVar2[1];
        }
        else {
          if (local_30 != 0x10) goto LAB_081c26b9;
          param_2->broken = 3;
        }
        ai = (ASN1_INTEGER *)0x0;
        if (*piVar3 == 2) {
          ai = (ASN1_INTEGER *)piVar3[1];
          goto LAB_081c2798;
        }
      }
    }
LAB_081c26b9:
    ctx = (BN_CTX *)0x0;
    ERR_put_error(10,0x73,0x72,"dsa_ameth.c",0x110);
    r = (DSA *)0x0;
LAB_081c26d8:
    iVar1 = 0;
    DSA_free(r);
  }
  else {
    local_24 = local_38;
    ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_38,local_34);
    if (ai == (ASN1_INTEGER *)0x0) {
LAB_081c28b0:
      ai = (ASN1_INTEGER *)0x0;
LAB_081c26b7:
      st = (_STACK *)0x0;
      goto LAB_081c26b9;
    }
    if (ai->type == 0x102) {
      param_2->broken = 4;
      ASN1_STRING_clear_free(ai);
      ai = d2i_ASN1_UINTEGER((ASN1_INTEGER **)0x0,&local_24,local_34);
      if (ai == (ASN1_INTEGER *)0x0) goto LAB_081c28b0;
    }
    st = (_STACK *)0x0;
    if (local_30 != 0x10) goto LAB_081c26b7;
LAB_081c2798:
    local_24 = (uchar *)local_2c[2];
    r = d2i_DSAparams((DSA **)0x0,&local_24,*local_2c);
    if (r == (DSA *)0x0) goto LAB_081c26b9;
    pBVar4 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
    r->priv_key = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) {
      iVar5 = 0xf8;
      iVar1 = 0x6d;
LAB_081c28f8:
      ctx = (BN_CTX *)0x0;
      ERR_put_error(10,0x73,iVar1,"dsa_ameth.c",iVar5);
      goto LAB_081c26d8;
    }
    pBVar4 = BN_new();
    r->pub_key = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) {
      iVar5 = 0xfd;
      iVar1 = 0x41;
      goto LAB_081c28f8;
    }
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      iVar5 = 0x101;
      iVar1 = 0x41;
LAB_081c2846:
      ERR_put_error(10,0x73,iVar1,"dsa_ameth.c",iVar5);
      goto LAB_081c26d8;
    }
    iVar1 = BN_mod_exp(r->pub_key,r->g,r->priv_key,r->p,ctx);
    if (iVar1 == 0) {
      iVar5 = 0x106;
      iVar1 = 0x6d;
      goto LAB_081c2846;
    }
    iVar1 = 1;
    EVP_PKEY_assign(param_1,0x74,r);
  }
  BN_CTX_free(ctx);
  if (st == (_STACK *)0x0) {
    ASN1_STRING_clear_free(ai);
  }
  else {
    sk_pop_free(st,ASN1_TYPE_free);
  }
LAB_081c2639:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

