
undefined4
dump_certs_pkeys_bags
          (BIO *param_1,_STACK *param_2,char *param_3,int param_4,uint param_5,void *param_6)

{
  _STACK *p_Var1;
  X509_ALGOR *pXVar2;
  ASN1_STRING *pAVar3;
  uint uVar4;
  int iVar5;
  PKCS12_SAFEBAG *bag;
  void *pvVar6;
  int iVar7;
  EVP_PKEY *pEVar8;
  ASN1_TYPE *pAVar9;
  X509 *x;
  PKCS8_PRIV_KEY_INFO *pPVar10;
  undefined4 uVar11;
  PBEPARAM *a;
  long lVar12;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  iVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar4 = param_5 & 4;
  do {
    iVar5 = sk_num(param_2);
    if (iVar5 <= iVar15) {
      uVar11 = 1;
LAB_08083fca:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uVar11;
    }
    bag = (PKCS12_SAFEBAG *)sk_value(param_2,iVar15);
    iVar5 = OBJ_obj2nid(bag->type);
    if (iVar5 == 0x97) {
      if (uVar4 != 0) {
        BIO_printf(bio_err,"Shrouded Keybag: ");
        pXVar2 = ((bag->value).shkeybag)->algor;
        pAVar3 = (pXVar2->parameter->value).asn1_string;
        local_24 = pAVar3->data;
        a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_24,pAVar3->length);
        if (a != (PBEPARAM *)0x0) {
          lVar12 = ASN1_INTEGER_get(a->iter);
          iVar5 = OBJ_obj2nid(pXVar2->algorithm);
          pcVar13 = OBJ_nid2ln(iVar5);
          BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar13,lVar12);
          PBEPARAM_free(a);
        }
      }
      if ((param_5 & 1) == 0) {
        print_attribs(param_1,bag->attrib,"Bag Attributes");
        pPVar10 = PKCS12_decrypt_skey(bag,param_3,param_4);
        if (pPVar10 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar8 = EVP_PKCS82PKEY(pPVar10);
          if (pEVar8 != (EVP_PKEY *)0x0) {
            print_attribs(param_1,pPVar10->attributes,"Key Attributes");
            PKCS8_PRIV_KEY_INFO_free(pPVar10);
            PEM_write_bio_PrivateKey(param_1,pEVar8,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
            EVP_PKEY_free(pEVar8);
            goto LAB_08083da8;
          }
          PKCS8_PRIV_KEY_INFO_free(pPVar10);
        }
LAB_08083fc8:
        uVar11 = 0;
        goto LAB_08083fca;
      }
    }
    else if (iVar5 < 0x98) {
      if (iVar5 == 0x96) {
        if (uVar4 != 0) {
          BIO_printf(bio_err,"Key bag\n");
        }
        if ((param_5 & 1) == 0) {
          print_attribs(param_1,bag->attrib,"Bag Attributes");
          pPVar10 = (bag->value).keybag;
          pEVar8 = EVP_PKCS82PKEY(pPVar10);
          if (pEVar8 == (EVP_PKEY *)0x0) goto LAB_08083fc8;
          print_attribs(param_1,pPVar10->attributes,"Key Attributes");
          PEM_write_bio_PrivateKey(param_1,pEVar8,enc,(uchar *)0x0,0,(undefined1 *)0x0,param_6);
          EVP_PKEY_free(pEVar8);
        }
      }
      else {
LAB_08083ee0:
        BIO_printf(bio_err,"Warning unsupported bag type: ");
        i2a_ASN1_OBJECT(bio_err,bag->type);
        BIO_printf(bio_err,"\n");
      }
    }
    else if (iVar5 == 0x98) {
      if (uVar4 != 0) {
        BIO_printf(bio_err,"Certificate bag\n");
      }
      if ((param_5 & 2) == 0) {
        pAVar9 = PKCS12_get_attr_gen(bag->attrib,0x9d);
        uVar14 = param_5 & 8;
        if (pAVar9 != (ASN1_TYPE *)0x0) {
          uVar14 = param_5 & 0x10;
        }
        if (uVar14 == 0) {
          print_attribs(param_1,bag->attrib,"Bag Attributes");
          iVar5 = OBJ_obj2nid(((bag->value).bag)->type);
          if (iVar5 == 0x9e) {
            x = PKCS12_certbag2x509(bag);
            if (x == (X509 *)0x0) goto LAB_08083fc8;
            dump_cert_text(param_1,x);
            PEM_write_bio_X509(param_1,x);
            X509_free(x);
          }
        }
      }
    }
    else {
      if (iVar5 != 0x9b) goto LAB_08083ee0;
      if (uVar4 != 0) {
        BIO_printf(bio_err,"Safe Contents bag\n");
      }
      print_attribs(param_1,bag->attrib,"Bag Attributes");
      p_Var1 = (_STACK *)(bag->value).bag;
      for (iVar5 = 0; iVar7 = sk_num(p_Var1), iVar5 < iVar7; iVar5 = iVar5 + 1) {
        pvVar6 = sk_value(p_Var1,iVar5);
        iVar7 = dump_certs_pkeys_bag(param_1,pvVar6,param_3,param_4,param_5,param_6);
        if (iVar7 == 0) goto LAB_08083fc8;
      }
    }
LAB_08083da8:
    iVar15 = iVar15 + 1;
  } while( true );
}

