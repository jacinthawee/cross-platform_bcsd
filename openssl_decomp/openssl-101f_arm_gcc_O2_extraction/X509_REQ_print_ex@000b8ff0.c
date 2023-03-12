
int X509_REQ_print_ex(BIO *bp,X509_REQ *x,ulong nmflag,ulong cflag)

{
  uint uVar1;
  int iVar2;
  EVP_PKEY *pkey;
  ASN1_OBJECT **ppAVar3;
  _STACK *p_Var4;
  X509_EXTENSION *ex;
  ASN1_OBJECT *pAVar5;
  char *pcVar6;
  ASN1_OBJECT **ppAVar7;
  ASN1_INTEGER *pAVar8;
  byte *pbVar9;
  ASN1_OBJECT *pAVar11;
  ASN1_OBJECT *pAVar12;
  ASN1_OBJECT *pAVar13;
  X509_REQ_INFO *pXVar14;
  undefined4 uVar15;
  int iVar16;
  bool bVar17;
  int local_34;
  byte *pbVar10;
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar16 = 0xc;
    uVar15 = 10;
  }
  else {
    if (nmflag == 0) {
      iVar16 = 0x10;
    }
    else {
      iVar16 = 0;
    }
    uVar15 = 0x20;
  }
  pXVar14 = x->req_info;
  if (((int)(cflag << 0x1f) < 0) ||
     ((iVar2 = BIO_write(bp,"Certificate Request:\n",0x15), 0 < iVar2 &&
      (iVar2 = BIO_write(bp,"    Data:\n",10), 0 < iVar2)))) {
    uVar1 = cflag & 2;
    if (uVar1 == 0) {
      pAVar8 = pXVar14->version;
      pcVar6 = "";
      if (pAVar8->type == 0x102) {
        pcVar6 = "-";
      }
      if (0 < pAVar8->length) {
        pbVar10 = pAVar8->data;
        do {
          pbVar9 = pbVar10 + 1;
          uVar1 = (uint)*pbVar10 + uVar1 * 0x100;
          pbVar10 = pbVar9;
        } while (pbVar9 != pAVar8->data + pAVar8->length);
      }
      iVar2 = BIO_printf(bp,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar6,uVar1,pcVar6,uVar1);
      if (iVar2 < 1) goto LAB_000b90b6;
    }
    if (((int)(cflag << 0x19) < 0) ||
       (((iVar2 = BIO_printf(bp,"        Subject:%c",uVar15), 0 < iVar2 &&
         (iVar16 = X509_NAME_print_ex(bp,pXVar14->subject,iVar16,nmflag), -1 < iVar16)) &&
        (iVar16 = BIO_write(bp,"\n",1), 0 < iVar16)))) {
      if ((cflag & 0x80) == 0) {
        iVar16 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
        if (((iVar16 < 1) || (iVar16 = BIO_printf(bp,"%12sPublic Key Algorithm: ",""), iVar16 < 1))
           || ((iVar16 = i2a_ASN1_OBJECT(bp,pXVar14->pubkey->algor->algorithm), iVar16 < 1 ||
               (iVar16 = BIO_puts(bp,"\n"), iVar16 < 1)))) goto LAB_000b90b6;
        pkey = X509_REQ_get_pubkey(x);
        if (pkey == (EVP_PKEY *)0x0) {
          BIO_printf(bp,"%12sUnable to load Public Key\n","");
          ERR_print_errors(bp);
        }
        else {
          EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
          EVP_PKEY_free(pkey);
        }
      }
      uVar1 = cflag & 0x800;
      if (uVar1 == 0) {
        iVar16 = BIO_printf(bp,"%8sAttributes:\n","");
        if (iVar16 < 1) goto LAB_000b90b6;
        p_Var4 = (_STACK *)x->req_info->attributes;
        iVar16 = sk_num(p_Var4);
        if (iVar16 == 0) {
          iVar16 = BIO_printf(bp,"%12sa0:00\n","");
          if (iVar16 < 1) goto LAB_000b90b6;
        }
        else {
          iVar16 = sk_num(p_Var4);
          if (0 < iVar16) {
            do {
              ppAVar3 = (ASN1_OBJECT **)sk_value(p_Var4,uVar1);
              iVar16 = OBJ_obj2nid(*ppAVar3);
              pAVar5 = (ASN1_OBJECT *)X509_REQ_extension_nid(iVar16);
              if (pAVar5 == (ASN1_OBJECT *)0x0) {
                iVar16 = BIO_printf(bp,"%12s","");
                if (iVar16 < 1) goto LAB_000b90b6;
                iVar16 = i2a_ASN1_OBJECT(bp,*ppAVar3);
                if (iVar16 < 1) {
                  local_34 = 1;
                  pAVar12 = pAVar5;
                  pAVar13 = pAVar5;
                }
                else {
                  pAVar11 = ppAVar3[1];
                  if (pAVar11 == (ASN1_OBJECT *)0x0) {
                    local_34 = sk_num((_STACK *)ppAVar3[2]);
                    goto LAB_000b93d2;
                  }
                  local_34 = 1;
                  pAVar12 = (ASN1_OBJECT *)ppAVar3[2]->sn;
                  pAVar13 = (ASN1_OBJECT *)ppAVar3[2]->ln;
                }
                while( true ) {
                  iVar16 = 0x19 - iVar16;
                  if (0 < iVar16) {
                    do {
                      iVar2 = BIO_write(bp,&DAT_00131dd0,1);
                      if (iVar2 != 1) goto LAB_000b90b6;
                      iVar16 = iVar16 + -1;
                    } while (iVar16 != 0);
                  }
                  iVar2 = BIO_puts(bp,":");
                  if (iVar2 < 1) goto LAB_000b90b6;
                  bVar17 = (ASN1_OBJECT *)&DAT_00000015 < pAVar12;
                  if (pAVar12 != (ASN1_OBJECT *)0x16) {
                    bVar17 = pAVar12 != (ASN1_OBJECT *)0x13;
                  }
                  if (bVar17 && (pAVar12 != (ASN1_OBJECT *)0x16 &&
                                pAVar12 != (ASN1_OBJECT *)&DAT_00000014)) {
                    BIO_puts(bp,"unable to print attribute\n");
                  }
                  else {
                    pcVar6 = (char *)BIO_write(bp,(void *)pAVar13->nid,(int)pAVar13->sn);
                    if (pcVar6 != pAVar13->sn) goto LAB_000b90b6;
                    BIO_puts(bp,"\n");
                  }
                  pAVar11 = (ASN1_OBJECT *)((int)&pAVar5->sn + 1);
                  if (local_34 <= (int)pAVar11) break;
LAB_000b93d2:
                  ppAVar7 = (ASN1_OBJECT **)sk_value((_STACK *)ppAVar3[2],(int)pAVar11);
                  pAVar12 = *ppAVar7;
                  pAVar13 = ppAVar7[1];
                  pAVar5 = pAVar11;
                }
              }
              uVar1 = uVar1 + 1;
              iVar16 = sk_num(p_Var4);
            } while ((int)uVar1 < iVar16);
          }
        }
      }
      if (((cflag & 0x100) == 0) &&
         (p_Var4 = (_STACK *)X509_REQ_get_extensions(x), p_Var4 != (_STACK *)0x0)) {
        BIO_printf(bp,"%8sRequested Extensions:\n","");
        uVar1 = cflag & 0x100;
        do {
          iVar16 = sk_num(p_Var4);
          if (iVar16 <= (int)uVar1) {
            sk_pop_free(p_Var4,X509_EXTENSION_free + 1);
            goto LAB_000b909c;
          }
          ex = (X509_EXTENSION *)sk_value(p_Var4,uVar1);
          iVar16 = BIO_printf(bp,"%12s","");
          if (iVar16 < 1) break;
          pAVar5 = X509_EXTENSION_get_object(ex);
          i2a_ASN1_OBJECT(bp,pAVar5);
          X509_EXTENSION_get_critical(ex);
          iVar16 = BIO_printf(bp,": %s\n");
          if (iVar16 < 1) break;
          iVar16 = X509V3_EXT_print(bp,ex,cflag,0x10);
          if (iVar16 == 0) {
            BIO_printf(bp,"%16s","");
            ASN1_STRING_print(bp,ex->value);
          }
          iVar16 = BIO_write(bp,"\n",1);
          uVar1 = uVar1 + 1;
        } while (0 < iVar16);
      }
      else {
LAB_000b909c:
        if (((int)(cflag << 0x16) < 0) ||
           (iVar16 = X509_signature_print(bp,x->sig_alg,x->signature), iVar16 != 0)) {
          return 1;
        }
      }
    }
  }
LAB_000b90b6:
  ERR_put_error(0xb,0x79,7,"t_req.c",0x103);
  return 0;
}

