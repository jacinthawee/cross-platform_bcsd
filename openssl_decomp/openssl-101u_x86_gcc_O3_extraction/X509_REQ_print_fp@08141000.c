
int X509_REQ_print_fp(FILE *bp,X509_REQ *req)

{
  byte bVar1;
  X509_REQ_INFO *pXVar2;
  ASN1_INTEGER *pAVar3;
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar4;
  EVP_PKEY *pkey;
  ASN1_OBJECT **ppAVar5;
  _STACK *p_Var6;
  X509_EXTENSION *ex;
  ASN1_OBJECT *a;
  int iVar7;
  char **ppcVar8;
  char *pcVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  int iVar13;
  int local_2c;
  char **local_28;
  char *local_24;
  int local_20;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x7a,7,"t_req.c",0x50);
    return 0;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  pXVar2 = req->req_info;
  iVar4 = BIO_write(bp_00,"Certificate Request:\n",0x15);
  if ((0 < iVar4) && (iVar4 = BIO_write(bp_00,"    Data:\n",10), 0 < iVar4)) {
    pAVar3 = pXVar2->version;
    puVar12 = &DAT_081eca46;
    if (pAVar3->type == 0x102) {
      puVar12 = &DAT_0823b914;
    }
    if (pAVar3->length < 1) {
      iVar4 = 0;
    }
    else {
      pbVar10 = pAVar3->data;
      iVar4 = 0;
      pbVar11 = pbVar10 + pAVar3->length;
      do {
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        iVar4 = iVar4 * 0x100 + (uint)bVar1;
      } while (pbVar11 != pbVar10);
    }
    iVar4 = BIO_printf(bp_00,"%8sVersion: %s%lu (%s0x%lx)\n",&DAT_081eca46,puVar12,iVar4,puVar12,
                       iVar4);
    if (((((0 < iVar4) && (iVar4 = BIO_printf(bp_00,"        Subject:%c",0x20), 0 < iVar4)) &&
         (iVar4 = X509_NAME_print_ex(bp_00,pXVar2->subject,0x10,0), -1 < iVar4)) &&
        ((iVar4 = BIO_write(bp_00,&DAT_081f15cb,1), 0 < iVar4 &&
         (iVar4 = BIO_write(bp_00,"        Subject Public Key Info:\n",0x21), 0 < iVar4)))) &&
       ((iVar4 = BIO_printf(bp_00,"%12sPublic Key Algorithm: ",&DAT_081eca46), 0 < iVar4 &&
        ((iVar4 = i2a_ASN1_OBJECT(bp_00,pXVar2->pubkey->algor->algorithm), 0 < iVar4 &&
         (iVar4 = BIO_puts(bp_00,"\n"), 0 < iVar4)))))) {
      pkey = X509_REQ_get_pubkey(req);
      if (pkey == (EVP_PKEY *)0x0) {
        BIO_printf(bp_00,"%12sUnable to load Public Key\n",&DAT_081eca46);
        ERR_print_errors(bp_00);
      }
      else {
        EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pkey);
      }
      iVar4 = BIO_printf(bp_00,"%8sAttributes:\n",&DAT_081eca46);
      if (0 < iVar4) {
        iVar13 = 0;
        p_Var6 = (_STACK *)req->req_info->attributes;
        iVar4 = sk_num(p_Var6);
        if (iVar4 == 0) {
          iVar4 = BIO_printf(bp_00,"%12sa0:00\n",&DAT_081eca46);
          if (iVar4 < 1) goto LAB_08141250;
        }
        else {
          for (; iVar4 = sk_num(p_Var6), iVar13 < iVar4; iVar13 = iVar13 + 1) {
            ppAVar5 = (ASN1_OBJECT **)sk_value(p_Var6,iVar13);
            iVar4 = OBJ_obj2nid(*ppAVar5);
            iVar4 = X509_REQ_extension_nid(iVar4);
            if (iVar4 == 0) {
              iVar4 = BIO_printf(bp_00,"%12s",&DAT_081eca46);
              if (iVar4 < 1) goto LAB_08141250;
              iVar4 = i2a_ASN1_OBJECT(bp_00,*ppAVar5);
              if (iVar4 < 1) {
                local_2c = 0;
                local_20 = 1;
                local_24 = (char *)0x0;
                local_28 = (char **)0x0;
              }
              else {
                if (ppAVar5[1] == (ASN1_OBJECT *)0x0) {
                  local_20 = sk_num((_STACK *)ppAVar5[2]);
                  local_2c = 0;
                  goto LAB_081414f7;
                }
                local_2c = 0;
                local_20 = 1;
                local_24 = ppAVar5[2]->sn;
                local_28 = ppAVar5[2]->ln;
              }
              while( true ) {
                iVar4 = 0x19 - iVar4;
                if (0 < iVar4) {
                  do {
                    iVar7 = BIO_write(bp_00,&DAT_081f8b67,1);
                    if (iVar7 != 1) goto LAB_08141250;
                    iVar4 = iVar4 + -1;
                  } while (iVar4 != 0);
                }
                iVar7 = BIO_puts(bp_00,":");
                if (iVar7 < 1) goto LAB_08141250;
                if ((local_24 + -0x13 < (char *)0x2) || (local_24 == (char *)0x16)) {
                  pcVar9 = (char *)BIO_write(bp_00,local_28[2],(int)*local_28);
                  if (pcVar9 != *local_28) goto LAB_08141250;
                  BIO_puts(bp_00,"\n");
                }
                else {
                  BIO_puts(bp_00,"unable to print attribute\n");
                }
                local_2c = local_2c + 1;
                if (local_20 <= local_2c) break;
LAB_081414f7:
                ppcVar8 = (char **)sk_value((_STACK *)ppAVar5[2],local_2c);
                local_24 = *ppcVar8;
                local_28 = (char **)ppcVar8[1];
              }
            }
          }
        }
        p_Var6 = (_STACK *)X509_REQ_get_extensions(req);
        if (p_Var6 != (_STACK *)0x0) {
          BIO_printf(bp_00,"%8sRequested Extensions:\n",&DAT_081eca46);
          for (iVar4 = 0; iVar13 = sk_num(p_Var6), iVar4 < iVar13; iVar4 = iVar4 + 1) {
            ex = (X509_EXTENSION *)sk_value(p_Var6,iVar4);
            iVar13 = BIO_printf(bp_00,"%12s",&DAT_081eca46);
            if (iVar13 < 1) goto LAB_08141250;
            a = X509_EXTENSION_get_object(ex);
            i2a_ASN1_OBJECT(bp_00,a);
            iVar13 = X509_EXTENSION_get_critical(ex);
            pcVar9 = "critical";
            if (iVar13 == 0) {
              pcVar9 = "";
            }
            iVar13 = BIO_printf(bp_00,": %s\n",pcVar9);
            if (iVar13 < 1) goto LAB_08141250;
            iVar13 = X509V3_EXT_print(bp_00,ex,0,0x10);
            if (iVar13 == 0) {
              BIO_printf(bp_00,"%16s",&DAT_081eca46);
              ASN1_STRING_print(bp_00,ex->value);
            }
            iVar13 = BIO_write(bp_00,&DAT_081f15cb,1);
            if (iVar13 < 1) goto LAB_08141250;
          }
          sk_pop_free(p_Var6,X509_EXTENSION_free);
        }
        iVar4 = X509_signature_print(bp_00,req->sig_alg,req->signature);
        if (iVar4 != 0) {
          iVar4 = 1;
          goto LAB_0814126d;
        }
      }
    }
  }
LAB_08141250:
  iVar4 = 0;
  ERR_put_error(0xb,0x79,7,"t_req.c",0xf7);
LAB_0814126d:
  BIO_free(bp_00);
  return iVar4;
}

