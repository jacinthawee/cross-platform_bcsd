
uint dump_certs_pkeys_bag
               (BIO *param_1,PKCS12_SAFEBAG *param_2,char *param_3,int param_4,uint param_5,
               void *param_6)

{
  _STACK *p_Var1;
  _STACK *p_Var2;
  X509_ALGOR *pXVar3;
  ASN1_STRING *pAVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  PKCS12_SAFEBAG *bag;
  void *pvVar8;
  int iVar9;
  EVP_PKEY *pEVar10;
  ASN1_TYPE *pAVar11;
  X509 *pXVar12;
  PKCS8_PRIV_KEY_INFO *pPVar13;
  PBEPARAM *pPVar14;
  long lVar15;
  char *pcVar16;
  uint uVar17;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = OBJ_obj2nid(param_2->type);
  if (iVar5 == 0x97) {
    if ((param_5 & 4) != 0) {
      BIO_printf(bio_err,"Shrouded Keybag: ");
      pXVar3 = ((param_2->value).shkeybag)->algor;
      pAVar4 = (pXVar3->parameter->value).asn1_string;
      local_24 = pAVar4->data;
      pPVar14 = d2i_PBEPARAM((PBEPARAM **)0x0,&local_24,pAVar4->length);
      if (pPVar14 != (PBEPARAM *)0x0) {
        lVar15 = ASN1_INTEGER_get(pPVar14->iter);
        iVar5 = OBJ_obj2nid(pXVar3->algorithm);
        pcVar16 = OBJ_nid2ln(iVar5);
        BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar16,lVar15);
        PBEPARAM_free(pPVar14);
      }
    }
    param_5 = param_5 & 1;
    if (param_5 == 0) {
      print_attribs(param_1,param_2->attrib,"Bag Attributes");
      pPVar13 = PKCS12_decrypt_skey(param_2,param_3,param_4);
      if (pPVar13 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar10 = EVP_PKCS82PKEY(pPVar13);
        if (pEVar10 == (EVP_PKEY *)0x0) {
          PKCS8_PRIV_KEY_INFO_free(pPVar13);
        }
        else {
          param_5 = 1;
          print_attribs(param_1,pPVar13->attributes,"Key Attributes");
          PKCS8_PRIV_KEY_INFO_free(pPVar13);
          PEM_write_bio_PrivateKey(param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar10);
        }
        goto LAB_08081655;
      }
LAB_08081888:
      param_5 = 0;
      goto LAB_08081655;
    }
  }
  else if (iVar5 < 0x98) {
    if (iVar5 == 0x96) {
      if ((param_5 & 4) != 0) {
        BIO_printf(bio_err,"Key bag\n");
      }
      if ((param_5 & 1) == 0) {
        print_attribs(param_1,param_2->attrib,"Bag Attributes");
        pPVar13 = (param_2->value).keybag;
        pEVar10 = EVP_PKCS82PKEY(pPVar13);
        if (pEVar10 != (EVP_PKEY *)0x0) {
          param_5 = 1;
          print_attribs(param_1,pPVar13->attributes,"Key Attributes");
          PEM_write_bio_PrivateKey(param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar10);
          goto LAB_08081655;
        }
        goto LAB_08081888;
      }
    }
    else {
LAB_08081920:
      BIO_printf(bio_err,"Warning unsupported bag type: ");
      i2a_ASN1_OBJECT(bio_err,param_2->type);
      BIO_printf(bio_err,"\n");
    }
  }
  else if (iVar5 == 0x98) {
    if ((param_5 & 4) != 0) {
      BIO_printf(bio_err,"Certificate bag\n");
    }
    if ((param_5 & 2) == 0) {
      pAVar11 = PKCS12_get_attr_gen(param_2->attrib,0x9d);
      if (pAVar11 == (ASN1_TYPE *)0x0) {
        param_5 = param_5 & 8;
      }
      else {
        param_5 = param_5 & 0x10;
      }
      if (param_5 == 0) {
        print_attribs(param_1,param_2->attrib,"Bag Attributes");
        iVar5 = OBJ_obj2nid(((param_2->value).bag)->type);
        if (iVar5 == 0x9e) {
          pXVar12 = PKCS12_certbag2x509(param_2);
          if (pXVar12 != (X509 *)0x0) {
            param_5 = 1;
            dump_cert_text(param_1,pXVar12);
            PEM_write_bio_X509(param_1,pXVar12);
            X509_free(pXVar12);
            goto LAB_08081655;
          }
          goto LAB_08081888;
        }
      }
    }
  }
  else {
    if (iVar5 != 0x9b) goto LAB_08081920;
    uVar6 = param_5 & 4;
    if (uVar6 != 0) {
      BIO_printf(bio_err,"Safe Contents bag\n");
    }
    print_attribs(param_1,param_2->attrib,"Bag Attributes");
    p_Var1 = (_STACK *)(param_2->value).bag;
    for (iVar5 = 0; iVar7 = sk_num(p_Var1), iVar5 < iVar7; iVar5 = iVar5 + 1) {
      bag = (PKCS12_SAFEBAG *)sk_value(p_Var1,iVar5);
      iVar7 = OBJ_obj2nid(bag->type);
      if (iVar7 == 0x97) {
        if (uVar6 != 0) {
          BIO_printf(bio_err,"Shrouded Keybag: ");
          pXVar3 = ((bag->value).shkeybag)->algor;
          pAVar4 = (pXVar3->parameter->value).asn1_string;
          local_24 = pAVar4->data;
          pPVar14 = d2i_PBEPARAM((PBEPARAM **)0x0,&local_24,pAVar4->length);
          if (pPVar14 != (PBEPARAM *)0x0) {
            lVar15 = ASN1_INTEGER_get(pPVar14->iter);
            iVar7 = OBJ_obj2nid(pXVar3->algorithm);
            pcVar16 = OBJ_nid2ln(iVar7);
            BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar16,lVar15);
            PBEPARAM_free(pPVar14);
          }
        }
        if ((param_5 & 1) == 0) {
          print_attribs(param_1,bag->attrib,"Bag Attributes");
          pPVar13 = PKCS12_decrypt_skey(bag,param_3,param_4);
          if (pPVar13 == (PKCS8_PRIV_KEY_INFO *)0x0) goto LAB_08081888;
          pEVar10 = EVP_PKCS82PKEY(pPVar13);
          if (pEVar10 == (EVP_PKEY *)0x0) {
            PKCS8_PRIV_KEY_INFO_free(pPVar13);
            goto LAB_08081888;
          }
          print_attribs(param_1,pPVar13->attributes,"Key Attributes");
          PKCS8_PRIV_KEY_INFO_free(pPVar13);
          PEM_write_bio_PrivateKey(param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar10);
        }
      }
      else if (iVar7 < 0x98) {
        if (iVar7 == 0x96) {
          if (uVar6 != 0) {
            BIO_printf(bio_err,"Key bag\n");
          }
          if ((param_5 & 1) == 0) {
            print_attribs(param_1,bag->attrib,"Bag Attributes");
            pPVar13 = (bag->value).keybag;
            pEVar10 = EVP_PKCS82PKEY(pPVar13);
            if (pEVar10 == (EVP_PKEY *)0x0) goto LAB_08081888;
            print_attribs(param_1,pPVar13->attributes,"Key Attributes");
            PEM_write_bio_PrivateKey(param_1,pEVar10,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
            EVP_PKEY_free(pEVar10);
          }
        }
        else {
LAB_080817a0:
          BIO_printf(bio_err,"Warning unsupported bag type: ");
          i2a_ASN1_OBJECT(bio_err,bag->type);
          BIO_printf(bio_err,"\n");
        }
      }
      else if (iVar7 == 0x98) {
        if (uVar6 != 0) {
          BIO_printf(bio_err,"Certificate bag\n");
        }
        if ((param_5 & 2) == 0) {
          pAVar11 = PKCS12_get_attr_gen(bag->attrib,0x9d);
          uVar17 = param_5 & 8;
          if (pAVar11 != (ASN1_TYPE *)0x0) {
            uVar17 = param_5 & 0x10;
          }
          if (uVar17 == 0) {
            print_attribs(param_1,bag->attrib,"Bag Attributes");
            iVar7 = OBJ_obj2nid(((bag->value).bag)->type);
            if (iVar7 == 0x9e) {
              pXVar12 = PKCS12_certbag2x509(bag);
              if (pXVar12 == (X509 *)0x0) goto LAB_08081888;
              dump_cert_text(param_1,pXVar12);
              PEM_write_bio_X509(param_1,pXVar12);
              X509_free(pXVar12);
            }
          }
        }
      }
      else {
        if (iVar7 != 0x9b) goto LAB_080817a0;
        if (uVar6 != 0) {
          BIO_printf(bio_err,"Safe Contents bag\n");
        }
        print_attribs(param_1,bag->attrib,"Bag Attributes");
        p_Var2 = (_STACK *)(bag->value).bag;
        for (iVar7 = 0; iVar9 = sk_num(p_Var2), iVar7 < iVar9; iVar7 = iVar7 + 1) {
          pvVar8 = sk_value(p_Var2,iVar7);
          iVar9 = dump_certs_pkeys_bag(param_1,pvVar8,param_3,param_4,param_5,param_6);
          if (iVar9 == 0) goto LAB_08081888;
        }
      }
    }
  }
  param_5 = 1;
LAB_08081655:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_5;
}

