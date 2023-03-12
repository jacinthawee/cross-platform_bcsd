
undefined4
dump_certs_pkeys_bag
          (BIO *param_1,PKCS12_SAFEBAG *param_2,char *param_3,int param_4,uint param_5,void *param_6
          )

{
  uint uVar1;
  BIO *pBVar2;
  int iVar3;
  int iVar4;
  PKCS12_SAFEBAG *bag;
  PKCS8_PRIV_KEY_INFO *pPVar5;
  EVP_PKEY *pEVar6;
  void *pvVar7;
  int iVar8;
  ASN1_TYPE *pAVar9;
  X509 *pXVar10;
  PBEPARAM *pPVar11;
  char *pcVar12;
  long lVar13;
  uint uVar14;
  uchar *kstr;
  ASN1_STRING *pAVar15;
  _STACK *p_Var16;
  _STACK *p_Var17;
  X509_ALGOR *pXVar18;
  uchar *local_2c [2];
  
  iVar3 = OBJ_obj2nid(param_2->type);
  switch(iVar3) {
  case 0x96:
    if ((int)(param_5 << 0x1d) < 0) {
      BIO_printf(bio_err,"Key bag\n");
    }
    if ((param_5 & 1) == 0) {
      print_attribs(param_1,param_2->attrib,"Bag Attributes");
      pPVar5 = (param_2->value).keybag;
      pEVar6 = EVP_PKCS82PKEY(pPVar5);
      if (pEVar6 == (EVP_PKEY *)0x0) {
        return 0;
      }
      print_attribs(param_1,pPVar5->attributes,"Key Attributes");
LAB_00037e5e:
      kstr = (uchar *)(param_5 & 1);
      PEM_write_bio_PrivateKey(param_1,pEVar6,enc,kstr,(int)kstr,kstr,param_6);
      EVP_PKEY_free(pEVar6);
      return 1;
    }
    break;
  case 0x97:
    if ((int)(param_5 << 0x1d) < 0) {
      BIO_printf(bio_err,"Shrouded Keybag: ");
      pXVar18 = ((param_2->value).shkeybag)->algor;
      pAVar15 = (pXVar18->parameter->value).asn1_string;
      local_2c[0] = pAVar15->data;
      pPVar11 = d2i_PBEPARAM((PBEPARAM **)0x0,local_2c,pAVar15->length);
      pBVar2 = bio_err;
      if (pPVar11 != (PBEPARAM *)0x0) {
        iVar3 = OBJ_obj2nid(pXVar18->algorithm);
        pcVar12 = OBJ_nid2ln(iVar3);
        lVar13 = ASN1_INTEGER_get(pPVar11->iter);
        BIO_printf(pBVar2,"%s, Iteration %ld\n",pcVar12,lVar13);
        PBEPARAM_free(pPVar11);
      }
    }
    if ((param_5 & 1) == 0) {
      print_attribs(param_1,param_2->attrib,"Bag Attributes");
      pPVar5 = PKCS12_decrypt_skey(param_2,param_3,param_4);
      if (pPVar5 == (PKCS8_PRIV_KEY_INFO *)0x0) {
        return 0;
      }
      pEVar6 = EVP_PKCS82PKEY(pPVar5);
      if (pEVar6 == (EVP_PKEY *)0x0) {
        PKCS8_PRIV_KEY_INFO_free(pPVar5);
        return 0;
      }
      print_attribs(param_1,pPVar5->attributes,"Key Attributes");
      PKCS8_PRIV_KEY_INFO_free(pPVar5);
      goto LAB_00037e5e;
    }
    break;
  case 0x98:
    if ((int)(param_5 << 0x1d) < 0) {
      BIO_printf(bio_err,"Certificate bag\n");
    }
    if (-1 < (int)(param_5 << 0x1e)) {
      pAVar9 = PKCS12_get_attr_gen(param_2->attrib,0x9d);
      if (pAVar9 == (ASN1_TYPE *)0x0) {
        iVar3 = param_5 << 0x1c;
      }
      else {
        iVar3 = param_5 << 0x1b;
      }
      if (-1 < iVar3) {
        print_attribs(param_1,param_2->attrib,"Bag Attributes");
        iVar3 = OBJ_obj2nid(((param_2->value).bag)->type);
        if (iVar3 == 0x9e) {
          pXVar10 = PKCS12_certbag2x509(param_2);
          if (pXVar10 == (X509 *)0x0) {
            return 0;
          }
          dump_cert_text(param_1,pXVar10);
          PEM_write_bio_X509(param_1,pXVar10);
          X509_free(pXVar10);
          return 1;
        }
      }
    }
    break;
  default:
    BIO_printf(bio_err,"Warning unsupported bag type: ");
    i2a_ASN1_OBJECT(bio_err,param_2->type);
    BIO_printf(bio_err,"\n");
    return 1;
  case 0x9b:
    uVar14 = param_5 & 4;
    if (uVar14 != 0) {
      BIO_printf(bio_err,"Safe Contents bag\n");
    }
    print_attribs(param_1,param_2->attrib,"Bag Attributes");
    p_Var17 = (_STACK *)(param_2->value).bag;
    for (iVar3 = 0; iVar4 = sk_num(p_Var17), iVar3 < iVar4; iVar3 = iVar3 + 1) {
      bag = (PKCS12_SAFEBAG *)sk_value(p_Var17,iVar3);
      iVar4 = OBJ_obj2nid(bag->type);
      switch(iVar4) {
      case 0x96:
        if (uVar14 != 0) {
          BIO_printf(bio_err,"Key bag\n");
        }
        if ((param_5 & 1) == 0) {
          print_attribs(param_1,bag->attrib,"Bag Attributes");
          pPVar5 = (bag->value).keybag;
          pEVar6 = EVP_PKCS82PKEY(pPVar5);
          if (pEVar6 == (EVP_PKEY *)0x0) {
            return 0;
          }
          print_attribs(param_1,pPVar5->attributes,"Key Attributes");
          PEM_write_bio_PrivateKey(param_1,pEVar6,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar6);
        }
        break;
      case 0x97:
        if (uVar14 != 0) {
          BIO_printf(bio_err,"Shrouded Keybag: ");
          pXVar18 = ((bag->value).shkeybag)->algor;
          pAVar15 = (pXVar18->parameter->value).asn1_string;
          local_2c[0] = pAVar15->data;
          pPVar11 = d2i_PBEPARAM((PBEPARAM **)0x0,local_2c,pAVar15->length);
          pBVar2 = bio_err;
          if (pPVar11 != (PBEPARAM *)0x0) {
            iVar4 = OBJ_obj2nid(pXVar18->algorithm);
            pcVar12 = OBJ_nid2ln(iVar4);
            lVar13 = ASN1_INTEGER_get(pPVar11->iter);
            BIO_printf(pBVar2,"%s, Iteration %ld\n",pcVar12,lVar13);
            PBEPARAM_free(pPVar11);
          }
        }
        if ((param_5 & 1) == 0) {
          print_attribs(param_1,bag->attrib,"Bag Attributes");
          pPVar5 = PKCS12_decrypt_skey(bag,param_3,param_4);
          if (pPVar5 == (PKCS8_PRIV_KEY_INFO *)0x0) {
            return 0;
          }
          pEVar6 = EVP_PKCS82PKEY(pPVar5);
          if (pEVar6 == (EVP_PKEY *)0x0) {
            PKCS8_PRIV_KEY_INFO_free(pPVar5);
            return 0;
          }
          print_attribs(param_1,pPVar5->attributes,"Key Attributes");
          PKCS8_PRIV_KEY_INFO_free(pPVar5);
          PEM_write_bio_PrivateKey(param_1,pEVar6,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar6);
        }
        break;
      case 0x98:
        if (uVar14 != 0) {
          BIO_printf(bio_err,"Certificate bag\n");
        }
        if ((param_5 & 2) == 0) {
          pAVar9 = PKCS12_get_attr_gen(bag->attrib,0x9d);
          uVar1 = param_5 & 8;
          if (pAVar9 != (ASN1_TYPE *)0x0) {
            uVar1 = param_5 & 0x10;
          }
          if (uVar1 == 0) {
            print_attribs(param_1,bag->attrib,"Bag Attributes");
            iVar4 = OBJ_obj2nid(((bag->value).bag)->type);
            if (iVar4 == 0x9e) {
              pXVar10 = PKCS12_certbag2x509(bag);
              if (pXVar10 == (X509 *)0x0) {
                return 0;
              }
              dump_cert_text(param_1,pXVar10);
              PEM_write_bio_X509(param_1,pXVar10);
              X509_free(pXVar10);
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
        if (uVar14 != 0) {
          BIO_printf(bio_err,"Safe Contents bag\n");
        }
        print_attribs(param_1,bag->attrib,"Bag Attributes");
        p_Var16 = (_STACK *)(bag->value).bag;
        iVar4 = 0;
        while( true ) {
          iVar8 = sk_num(p_Var16);
          if (iVar8 <= iVar4) break;
          pvVar7 = sk_value(p_Var16,iVar4);
          iVar8 = dump_certs_pkeys_bag(param_1,pvVar7,param_3,param_4,param_5,param_6);
          iVar4 = iVar4 + 1;
          if (iVar8 == 0) {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}

