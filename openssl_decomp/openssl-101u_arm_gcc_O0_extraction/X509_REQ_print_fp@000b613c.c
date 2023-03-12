
int X509_REQ_print_fp(FILE *bp,X509_REQ *req)

{
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar1;
  EVP_PKEY *pkey;
  ASN1_OBJECT **ppAVar2;
  ASN1_OBJECT *pAVar3;
  X509_EXTENSION *ex;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  ASN1_INTEGER *pAVar6;
  byte *pbVar7;
  char *pcVar9;
  ASN1_OBJECT *pAVar10;
  X509_REQ_INFO *pXVar11;
  int iVar12;
  _STACK *p_Var13;
  bool bVar14;
  ASN1_OBJECT *local_30;
  int local_2c;
  byte *pbVar8;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x7a,7,"t_req.c",0x50);
    return 0;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  pXVar11 = req->req_info;
  iVar1 = BIO_write(bp_00,"Certificate Request:\n",0x15);
  if ((0 < iVar1) && (iVar1 = BIO_write(bp_00,"    Data:\n",10), 0 < iVar1)) {
    pAVar6 = pXVar11->version;
    pcVar9 = "";
    if (pAVar6->type == 0x102) {
      pcVar9 = "-";
    }
    if (pAVar6->length < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      pbVar8 = pAVar6->data;
      do {
        pbVar7 = pbVar8 + 1;
        iVar1 = (uint)*pbVar8 + iVar1 * 0x100;
        pbVar8 = pbVar7;
      } while (pbVar7 != pAVar6->data + pAVar6->length);
    }
    iVar1 = BIO_printf(bp_00,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar9,iVar1,pcVar9,iVar1);
    if (((((0 < iVar1) && (iVar1 = BIO_printf(bp_00,"        Subject:%c",0x20), 0 < iVar1)) &&
         (iVar1 = X509_NAME_print_ex(bp_00,pXVar11->subject,0x10,0), -1 < iVar1)) &&
        ((iVar1 = BIO_write(bp_00,"\n",1), 0 < iVar1 &&
         (iVar1 = BIO_write(bp_00,"        Subject Public Key Info:\n",0x21), 0 < iVar1)))) &&
       ((iVar1 = BIO_printf(bp_00,"%12sPublic Key Algorithm: ",""), 0 < iVar1 &&
        ((iVar1 = i2a_ASN1_OBJECT(bp_00,pXVar11->pubkey->algor->algorithm), 0 < iVar1 &&
         (iVar1 = BIO_puts(bp_00,"\n"), 0 < iVar1)))))) {
      pkey = X509_REQ_get_pubkey(req);
      if (pkey == (EVP_PKEY *)0x0) {
        BIO_printf(bp_00,"%12sUnable to load Public Key\n","");
        ERR_print_errors(bp_00);
      }
      else {
        EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pkey);
      }
      iVar1 = BIO_printf(bp_00,"%8sAttributes:\n","");
      if (0 < iVar1) {
        iVar12 = 0;
        p_Var13 = (_STACK *)req->req_info->attributes;
        iVar1 = sk_num(p_Var13);
        if (iVar1 == 0) {
          iVar1 = BIO_printf(bp_00,"%12sa0:00\n","");
          if (iVar1 < 1) goto LAB_000b63fa;
        }
        else {
          iVar1 = sk_num(p_Var13);
          if (0 < iVar1) {
            do {
              ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var13,iVar12);
              iVar1 = OBJ_obj2nid(*ppAVar2);
              pAVar3 = (ASN1_OBJECT *)X509_REQ_extension_nid(iVar1);
              if (pAVar3 == (ASN1_OBJECT *)0x0) {
                iVar1 = BIO_printf(bp_00,"%12s","");
                if (iVar1 < 1) goto LAB_000b63fa;
                iVar1 = i2a_ASN1_OBJECT(bp_00,*ppAVar2);
                if (iVar1 < 1) {
                  local_2c = 1;
                  pAVar10 = pAVar3;
                  local_30 = pAVar3;
                }
                else {
                  pAVar10 = ppAVar2[1];
                  if (pAVar10 == (ASN1_OBJECT *)0x0) {
                    local_2c = sk_num((_STACK *)ppAVar2[2]);
                    goto LAB_000b6516;
                  }
                  local_2c = 1;
                  pAVar10 = (ASN1_OBJECT *)ppAVar2[2]->sn;
                  local_30 = (ASN1_OBJECT *)ppAVar2[2]->ln;
                }
                while( true ) {
                  iVar1 = 0x19 - iVar1;
                  if (0 < iVar1) {
                    do {
                      iVar4 = BIO_write(bp_00,&DAT_00130f00,1);
                      if (iVar4 != 1) goto LAB_000b63fa;
                      iVar1 = iVar1 + -1;
                    } while (iVar1 != 0);
                  }
                  iVar4 = BIO_puts(bp_00,":");
                  if (iVar4 < 1) goto LAB_000b63fa;
                  bVar14 = (ASN1_OBJECT *)&DAT_00000015 < pAVar10;
                  if (pAVar10 != (ASN1_OBJECT *)0x16) {
                    bVar14 = pAVar10 != (ASN1_OBJECT *)0x13;
                  }
                  if (bVar14 && (pAVar10 != (ASN1_OBJECT *)0x16 &&
                                pAVar10 != (ASN1_OBJECT *)&DAT_00000014)) {
                    BIO_puts(bp_00,"unable to print attribute\n");
                  }
                  else {
                    pcVar9 = (char *)BIO_write(bp_00,(void *)local_30->nid,(int)local_30->sn);
                    if (pcVar9 != local_30->sn) goto LAB_000b63fa;
                    BIO_puts(bp_00,"\n");
                  }
                  pAVar10 = (ASN1_OBJECT *)((int)&pAVar3->sn + 1);
                  if (local_2c <= (int)pAVar10) break;
LAB_000b6516:
                  ppAVar5 = (ASN1_OBJECT **)sk_value((_STACK *)ppAVar2[2],(int)pAVar10);
                  pAVar3 = pAVar10;
                  pAVar10 = *ppAVar5;
                  local_30 = ppAVar5[1];
                }
              }
              iVar12 = iVar12 + 1;
              iVar1 = sk_num(p_Var13);
            } while (iVar12 < iVar1);
          }
        }
        p_Var13 = (_STACK *)X509_REQ_get_extensions(req);
        if (p_Var13 == (_STACK *)0x0) {
LAB_000b644c:
          iVar1 = X509_signature_print(bp_00,req->sig_alg,req->signature);
          if (iVar1 != 0) {
            iVar1 = 1;
            goto LAB_000b6412;
          }
        }
        else {
          BIO_printf(bp_00,"%8sRequested Extensions:\n","");
          iVar1 = 0;
          do {
            iVar12 = sk_num(p_Var13);
            if (iVar12 <= iVar1) {
              sk_pop_free(p_Var13,X509_EXTENSION_free + 1);
              goto LAB_000b644c;
            }
            ex = (X509_EXTENSION *)sk_value(p_Var13,iVar1);
            iVar12 = BIO_printf(bp_00,"%12s","");
            if (iVar12 < 1) break;
            pAVar3 = X509_EXTENSION_get_object(ex);
            i2a_ASN1_OBJECT(bp_00,pAVar3);
            X509_EXTENSION_get_critical(ex);
            iVar12 = BIO_printf(bp_00,": %s\n");
            if (iVar12 < 1) break;
            iVar12 = X509V3_EXT_print(bp_00,ex,0,0x10);
            if (iVar12 == 0) {
              BIO_printf(bp_00,"%16s","");
              ASN1_STRING_print(bp_00,ex->value);
            }
            iVar12 = BIO_write(bp_00,"\n",1);
            iVar1 = iVar1 + 1;
          } while (0 < iVar12);
        }
      }
    }
  }
LAB_000b63fa:
  iVar1 = 0;
  ERR_put_error(0xb,0x79,7,"t_req.c",0xf7);
LAB_000b6412:
  BIO_free(bp_00);
  return iVar1;
}

