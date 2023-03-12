
_STACK * dump_certs_keys_p12(BIO *param_1,PKCS12 *param_2,char *param_3,int param_4,uint param_5,
                            void *param_6)

{
  uint uVar1;
  BIO *pBVar2;
  _STACK *st;
  int iVar3;
  PKCS7 *p7;
  _STACK *st_00;
  PKCS12_SAFEBAG *bag;
  void *pvVar4;
  int iVar5;
  PKCS8_PRIV_KEY_INFO *pPVar6;
  EVP_PKEY *pEVar7;
  X509 *x;
  PBEPARAM *pPVar8;
  char *pcVar9;
  long lVar10;
  ASN1_STRING *pAVar11;
  char **ppcVar12;
  uint uVar13;
  X509_ALGOR *pXVar14;
  int iVar15;
  ASN1_TYPE *pAVar16;
  _STACK *p_Var17;
  int local_54;
  uchar *local_2c [2];
  
  st = (_STACK *)PKCS12_unpack_authsafes(param_2);
  if (st == (_STACK *)0x0) {
    return (_STACK *)0x0;
  }
  uVar13 = param_5 & 4;
  for (local_54 = 0; iVar3 = sk_num(st), local_54 < iVar3; local_54 = local_54 + 1) {
    p7 = (PKCS7 *)sk_value(st,local_54);
    iVar3 = OBJ_obj2nid(p7->type);
    if (iVar3 == 0x15) {
      st_00 = (_STACK *)PKCS12_unpack_p7data(p7);
      if (uVar13 != 0) {
        BIO_printf(bio_err,"PKCS7 Data\n");
      }
LAB_00037ffc:
      p_Var17 = st_00;
      if (st_00 == (_STACK *)0x0) goto LAB_0003821c;
      iVar15 = 0;
      iVar3 = sk_num(st_00);
      if (0 < iVar3) {
        do {
          bag = (PKCS12_SAFEBAG *)sk_value(st_00,iVar15);
          iVar3 = OBJ_obj2nid(bag->type);
          switch(iVar3) {
          case 0x96:
            if (uVar13 != 0) {
              BIO_printf(bio_err,"Key bag\n");
            }
            if ((param_5 & 1) == 0) {
              print_attribs(param_1,bag->attrib,"Bag Attributes");
              pPVar6 = (bag->value).keybag;
              pEVar7 = EVP_PKCS82PKEY(pPVar6);
              if (pEVar7 == (EVP_PKEY *)0x0) goto LAB_0003820c;
              print_attribs(param_1,pPVar6->attributes,"Key Attributes");
              PEM_write_bio_PrivateKey(param_1,pEVar7,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
              EVP_PKEY_free(pEVar7);
            }
            break;
          case 0x97:
            if (uVar13 != 0) {
              BIO_printf(bio_err,"Shrouded Keybag: ");
              pXVar14 = ((bag->value).shkeybag)->algor;
              pAVar11 = (pXVar14->parameter->value).asn1_string;
              local_2c[0] = pAVar11->data;
              pPVar8 = d2i_PBEPARAM((PBEPARAM **)0x0,local_2c,pAVar11->length);
              pBVar2 = bio_err;
              if (pPVar8 != (PBEPARAM *)0x0) {
                iVar3 = OBJ_obj2nid(pXVar14->algorithm);
                pcVar9 = OBJ_nid2ln(iVar3);
                lVar10 = ASN1_INTEGER_get(pPVar8->iter);
                BIO_printf(pBVar2,"%s, Iteration %ld\n",pcVar9,lVar10);
                PBEPARAM_free(pPVar8);
              }
            }
            if ((param_5 & 1) == 0) {
              print_attribs(param_1,bag->attrib,"Bag Attributes");
              pPVar6 = PKCS12_decrypt_skey(bag,param_3,param_4);
              if (pPVar6 != (PKCS8_PRIV_KEY_INFO *)0x0) {
                pEVar7 = EVP_PKCS82PKEY(pPVar6);
                if (pEVar7 != (EVP_PKEY *)0x0) {
                  print_attribs(param_1,pPVar6->attributes,"Key Attributes");
                  PKCS8_PRIV_KEY_INFO_free(pPVar6);
                  PEM_write_bio_PrivateKey
                            (param_1,pEVar7,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
                  EVP_PKEY_free(pEVar7);
                  break;
                }
                PKCS8_PRIV_KEY_INFO_free(pPVar6);
              }
LAB_0003820c:
              p_Var17 = (_STACK *)0x0;
              sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
              goto LAB_0003821c;
            }
            break;
          case 0x98:
            if (uVar13 != 0) {
              BIO_printf(bio_err,"Certificate bag\n");
            }
            if ((param_5 & 2) == 0) {
              pAVar16 = PKCS12_get_attr_gen(bag->attrib,0x9d);
              uVar1 = param_5 & 8;
              if (pAVar16 != (ASN1_TYPE *)0x0) {
                uVar1 = param_5 & 0x10;
              }
              if (uVar1 == 0) {
                print_attribs(param_1,bag->attrib,"Bag Attributes");
                iVar3 = OBJ_obj2nid(((bag->value).bag)->type);
                if (iVar3 == 0x9e) {
                  x = PKCS12_certbag2x509(bag);
                  if (x == (X509 *)0x0) goto LAB_0003820c;
                  dump_cert_text(param_1,x);
                  PEM_write_bio_X509(param_1,x);
                  X509_free(x);
                }
              }
            }
            break;
          default:
            BIO_printf(bio_err,"Warning unsupported bag type: ");
            i2a_ASN1_OBJECT(bio_err,bag->type);
            BIO_printf(bio_err,"\n");
            break;
          case 0x9b:
            if (uVar13 != 0) {
              BIO_printf(bio_err,"Safe Contents bag\n");
            }
            print_attribs(param_1,bag->attrib,"Bag Attributes");
            p_Var17 = (_STACK *)(bag->value).bag;
            iVar3 = 0;
            while( true ) {
              iVar5 = sk_num(p_Var17);
              if (iVar5 <= iVar3) break;
              pvVar4 = sk_value(p_Var17,iVar3);
              iVar5 = dump_certs_pkeys_bag(param_1,pvVar4,param_3,param_4,param_5,param_6);
              iVar3 = iVar3 + 1;
              if (iVar5 == 0) goto LAB_0003820c;
            }
          }
          iVar15 = iVar15 + 1;
          iVar3 = sk_num(st_00);
        } while (iVar15 < iVar3);
      }
      sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
    }
    else if (iVar3 == 0x1a) {
      if (uVar13 != 0) {
        BIO_printf(bio_err,"PKCS7 Encrypted data: ");
        pAVar16 = ((p7->d).digest)->md->parameter;
        ppcVar12 = ((pAVar16->value).object)->ln;
        local_2c[0] = (uchar *)ppcVar12[2];
        pPVar8 = d2i_PBEPARAM((PBEPARAM **)0x0,local_2c,(long)*ppcVar12);
        pBVar2 = bio_err;
        if (pPVar8 != (PBEPARAM *)0x0) {
          iVar3 = OBJ_obj2nid((ASN1_OBJECT *)pAVar16->type);
          pcVar9 = OBJ_nid2ln(iVar3);
          lVar10 = ASN1_INTEGER_get(pPVar8->iter);
          BIO_printf(pBVar2,"%s, Iteration %ld\n",pcVar9,lVar10);
          PBEPARAM_free(pPVar8);
        }
      }
      st_00 = (_STACK *)PKCS12_unpack_p7encdata(p7,param_3,param_4);
      goto LAB_00037ffc;
    }
  }
  p_Var17 = (_STACK *)0x1;
LAB_0003821c:
  sk_pop_free(st,PKCS7_free + 1);
  return p_Var17;
}

