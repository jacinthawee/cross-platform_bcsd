
undefined4
dump_certs_keys_p12(BIO *param_1,PKCS12 *param_2,char *param_3,int param_4,uint param_5,
                   void *param_6)

{
  _STACK *p_Var1;
  X509_ALGOR *pXVar2;
  ASN1_STRING *pAVar3;
  char **ppcVar4;
  _STACK *st;
  uint uVar5;
  int iVar6;
  PKCS7 *p7;
  int iVar7;
  PKCS12_SAFEBAG *bag;
  void *pvVar8;
  int iVar9;
  EVP_PKEY *pEVar10;
  PKCS8_PRIV_KEY_INFO *pPVar11;
  ASN1_TYPE *pAVar12;
  X509 *x;
  PBEPARAM *pPVar13;
  long lVar14;
  char *pcVar15;
  uint uVar16;
  undefined4 uVar17;
  int in_GS_OFFSET;
  _STACK *local_5c;
  int local_50;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = (_STACK *)PKCS12_unpack_authsafes(param_2);
  if (st == (_STACK *)0x0) {
    uVar17 = 0;
  }
  else {
    uVar5 = param_5 & 4;
    for (local_50 = 0; iVar6 = sk_num(st), local_50 < iVar6; local_50 = local_50 + 1) {
      p7 = (PKCS7 *)sk_value(st,local_50);
      iVar6 = OBJ_obj2nid(p7->type);
      if (iVar6 == 0x15) {
        local_5c = (_STACK *)PKCS12_unpack_p7data(p7);
        if (uVar5 == 0) goto LAB_08081d96;
        BIO_printf(bio_err,"PKCS7 Data\n");
        if (local_5c != (_STACK *)0x0) goto LAB_08081da1;
LAB_0808223d:
        uVar17 = 0;
        goto LAB_080820d6;
      }
      if (iVar6 == 0x1a) {
        if (uVar5 != 0) {
          BIO_printf(bio_err,"PKCS7 Encrypted data: ");
          pAVar12 = ((p7->d).digest)->md->parameter;
          ppcVar4 = ((pAVar12->value).object)->ln;
          local_24 = (uchar *)ppcVar4[2];
          pPVar13 = d2i_PBEPARAM((PBEPARAM **)0x0,&local_24,(long)*ppcVar4);
          if (pPVar13 != (PBEPARAM *)0x0) {
            lVar14 = ASN1_INTEGER_get(pPVar13->iter);
            iVar6 = OBJ_obj2nid((ASN1_OBJECT *)pAVar12->type);
            pcVar15 = OBJ_nid2ln(iVar6);
            BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar15,lVar14);
            PBEPARAM_free(pPVar13);
          }
        }
        local_5c = (_STACK *)PKCS12_unpack_p7encdata(p7,param_3,param_4);
LAB_08081d96:
        if (local_5c == (_STACK *)0x0) goto LAB_0808223d;
LAB_08081da1:
        for (iVar6 = 0; iVar7 = sk_num(local_5c), iVar6 < iVar7; iVar6 = iVar6 + 1) {
          bag = (PKCS12_SAFEBAG *)sk_value(local_5c,iVar6);
          iVar7 = OBJ_obj2nid(bag->type);
          if (iVar7 == 0x97) {
            if (uVar5 != 0) {
              BIO_printf(bio_err,"Shrouded Keybag: ");
              pXVar2 = ((bag->value).shkeybag)->algor;
              pAVar3 = (pXVar2->parameter->value).asn1_string;
              local_24 = pAVar3->data;
              pPVar13 = d2i_PBEPARAM((PBEPARAM **)0x0,&local_24,pAVar3->length);
              if (pPVar13 != (PBEPARAM *)0x0) {
                lVar14 = ASN1_INTEGER_get(pPVar13->iter);
                iVar7 = OBJ_obj2nid(pXVar2->algorithm);
                pcVar15 = OBJ_nid2ln(iVar7);
                BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar15,lVar14);
                PBEPARAM_free(pPVar13);
              }
            }
            if ((param_5 & 1) == 0) {
              print_attribs(param_1,bag->attrib,"Bag Attributes");
              pPVar11 = PKCS12_decrypt_skey(bag,param_3,param_4);
              if (pPVar11 != (PKCS8_PRIV_KEY_INFO *)0x0) {
                pEVar10 = EVP_PKCS82PKEY(pPVar11);
                if (pEVar10 != (EVP_PKEY *)0x0) {
                  print_attribs(param_1,pPVar11->attributes,"Key Attributes");
                  PKCS8_PRIV_KEY_INFO_free(pPVar11);
                  PEM_write_bio_PrivateKey
                            (param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
                  EVP_PKEY_free(pEVar10);
                  goto LAB_08081e90;
                }
                PKCS8_PRIV_KEY_INFO_free(pPVar11);
              }
LAB_080820c0:
              uVar17 = 0;
              sk_pop_free(local_5c,PKCS12_SAFEBAG_free);
              goto LAB_080820d6;
            }
          }
          else if (iVar7 < 0x98) {
            if (iVar7 == 0x96) {
              if (uVar5 != 0) {
                BIO_printf(bio_err,"Key bag\n");
              }
              if ((param_5 & 1) == 0) {
                print_attribs(param_1,bag->attrib,"Bag Attributes");
                pPVar11 = (bag->value).keybag;
                pEVar10 = EVP_PKCS82PKEY(pPVar11);
                if (pEVar10 == (EVP_PKEY *)0x0) goto LAB_080820c0;
                print_attribs(param_1,pPVar11->attributes,"Key Attributes");
                PEM_write_bio_PrivateKey
                          (param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
                EVP_PKEY_free(pEVar10);
              }
            }
            else {
LAB_08081fd0:
              BIO_printf(bio_err,"Warning unsupported bag type: ");
              i2a_ASN1_OBJECT(bio_err,bag->type);
              BIO_printf(bio_err,"\n");
            }
          }
          else if (iVar7 == 0x98) {
            if (uVar5 != 0) {
              BIO_printf(bio_err,"Certificate bag\n");
            }
            if ((param_5 & 2) == 0) {
              pAVar12 = PKCS12_get_attr_gen(bag->attrib,0x9d);
              uVar16 = param_5 & 8;
              if (pAVar12 != (ASN1_TYPE *)0x0) {
                uVar16 = param_5 & 0x10;
              }
              if (uVar16 == 0) {
                print_attribs(param_1,bag->attrib,"Bag Attributes");
                iVar7 = OBJ_obj2nid(((bag->value).bag)->type);
                if (iVar7 == 0x9e) {
                  x = PKCS12_certbag2x509(bag);
                  if (x == (X509 *)0x0) goto LAB_080820c0;
                  dump_cert_text(param_1,x);
                  PEM_write_bio_X509(param_1,x);
                  X509_free(x);
                }
              }
            }
          }
          else {
            if (iVar7 != 0x9b) goto LAB_08081fd0;
            if (uVar5 != 0) {
              BIO_printf(bio_err,"Safe Contents bag\n");
            }
            print_attribs(param_1,bag->attrib,"Bag Attributes");
            p_Var1 = (_STACK *)(bag->value).bag;
            for (iVar7 = 0; iVar9 = sk_num(p_Var1), iVar7 < iVar9; iVar7 = iVar7 + 1) {
              pvVar8 = sk_value(p_Var1,iVar7);
              iVar9 = dump_certs_pkeys_bag(param_1,pvVar8,param_3,param_4,param_5,param_6);
              if (iVar9 == 0) goto LAB_080820c0;
            }
          }
LAB_08081e90:
        }
        sk_pop_free(local_5c,PKCS12_SAFEBAG_free);
      }
    }
    uVar17 = 1;
LAB_080820d6:
    sk_pop_free(st,PKCS7_free);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
}

