
int X509_REQ_print_ex(BIO *bp,X509_REQ *x,ulong nmflag,ulong cflag)

{
  byte bVar1;
  ASN1_INTEGER *pAVar2;
  int iVar3;
  EVP_PKEY *pkey;
  ASN1_OBJECT **ppAVar4;
  int iVar5;
  int iVar6;
  ASN1_OBJECT *a;
  char **ppcVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  int iVar11;
  X509_REQ_INFO *pXVar12;
  undefined4 uVar13;
  stack_st_X509_ATTRIBUTE *psVar14;
  int local_48;
  char **local_40;
  char *local_3c;
  int local_38;
  
  if ((nmflag & 0xf0000) == 0x40000) {
    iVar11 = 0xc;
    uVar13 = 10;
  }
  else {
    iVar11 = 0x10;
    uVar13 = 0x20;
    if (nmflag != 0) {
      iVar11 = 0;
    }
  }
  pXVar12 = x->req_info;
  if (((cflag & 1) != 0) ||
     ((iVar3 = (*(code *)PTR_BIO_write_006a7f14)(bp,"Certificate Request:\n",0x15), 0 < iVar3 &&
      (iVar3 = (*(code *)PTR_BIO_write_006a7f14)(bp,"    Data:\n",10), 0 < iVar3)))) {
    if ((cflag & 2) == 0) {
      pAVar2 = pXVar12->version;
      if (pAVar2->type == 0x102) {
        pcVar10 = "-";
      }
      else {
        pcVar10 = "";
      }
      if (pAVar2->length < 1) {
        iVar3 = 0;
      }
      else {
        pbVar8 = pAVar2->data;
        iVar3 = 0;
        pbVar9 = pbVar8 + pAVar2->length;
        do {
          bVar1 = *pbVar8;
          pbVar8 = pbVar8 + 1;
          iVar3 = (uint)bVar1 + iVar3 * 0x100;
        } while (pbVar8 != pbVar9);
      }
      iVar3 = (*(code *)PTR_BIO_printf_006a7f38)
                        (bp,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar10,iVar3,pcVar10,iVar3);
      if (iVar3 < 1) goto LAB_00559684;
    }
    if (((cflag & 0x40) != 0) ||
       (((iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"        Subject:%c",uVar13), 0 < iVar3 &&
         (iVar11 = X509_NAME_print_ex(bp,pXVar12->subject,iVar11,nmflag), -1 < iVar11)) &&
        (iVar11 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1), 0 < iVar11)))) {
      if ((cflag & 0x80) == 0) {
        iVar11 = (*(code *)PTR_BIO_write_006a7f14)(bp,"        Subject Public Key Info:\n",0x21);
        if (((iVar11 < 1) ||
            (iVar11 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sPublic Key Algorithm: ",""),
            iVar11 < 1)) ||
           ((iVar11 = i2a_ASN1_OBJECT(bp,pXVar12->pubkey->algor->algorithm), iVar11 < 1 ||
            (iVar11 = (*(code *)PTR_BIO_puts_006a8058)(bp,"\n"), iVar11 < 1)))) goto LAB_00559684;
        pkey = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(x);
        if (pkey == (EVP_PKEY *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sUnable to load Public Key\n","");
          (*(code *)PTR_ERR_print_errors_006a7f40)(bp);
        }
        else {
          EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
          EVP_PKEY_free(pkey);
        }
      }
      if ((cflag & 0x800) == 0) {
        iVar11 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sAttributes:\n","");
        if (iVar11 < 1) goto LAB_00559684;
        psVar14 = x->req_info->attributes;
        iVar11 = (*(code *)PTR_sk_num_006a7f2c)(psVar14);
        if (iVar11 == 0) {
          iVar11 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sa0:00\n","");
          if (iVar11 < 1) goto LAB_00559684;
        }
        else {
          for (iVar11 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar14), iVar11 < iVar3;
              iVar11 = iVar11 + 1) {
            ppAVar4 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a7f24)(psVar14,iVar11);
            uVar13 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*ppAVar4);
            iVar3 = (*(code *)PTR_X509_REQ_extension_nid_006a9e68)(uVar13);
            if (iVar3 == 0) {
              iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a4d0,"");
              if (iVar3 < 1) goto LAB_00559684;
              iVar3 = i2a_ASN1_OBJECT(bp,*ppAVar4);
              if (iVar3 < 1) {
                local_48 = 0;
                local_3c = (char *)0x0;
                local_40 = (char **)0x0;
                local_38 = 1;
              }
              else {
                if (ppAVar4[1] == (ASN1_OBJECT *)0x0) {
                  local_38 = (*(code *)PTR_sk_num_006a7f2c)(ppAVar4[2]);
                  local_48 = 0;
                  goto LAB_00559bf8;
                }
                local_48 = 0;
                local_38 = 1;
                local_3c = ppAVar4[2]->sn;
                local_40 = ppAVar4[2]->ln;
              }
              while( true ) {
                iVar3 = 0x19 - iVar3;
                if (0 < iVar3) {
                  do {
                    iVar5 = (*(code *)PTR_BIO_write_006a7f14)(bp,&DAT_0063f0b8,1);
                    iVar3 = iVar3 + -1;
                    if (iVar5 != 1) goto LAB_00559684;
                  } while (iVar3 != 0);
                }
                iVar5 = (*(code *)PTR_BIO_puts_006a8058)(bp,":");
                if (iVar5 < 1) goto LAB_00559684;
                if ((local_3c + -0x13 < (char *)0x2) || (local_3c == (char *)0x16)) {
                  pcVar10 = (char *)(*(code *)PTR_BIO_write_006a7f14)(bp,local_40[2],*local_40);
                  if (pcVar10 != *local_40) goto LAB_00559684;
                  (*(code *)PTR_BIO_puts_006a8058)(bp,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a8058)(bp,"unable to print attribute\n");
                }
                local_48 = local_48 + 1;
                if (local_38 <= local_48) break;
LAB_00559bf8:
                ppcVar7 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppAVar4[2],local_48);
                local_3c = *ppcVar7;
                local_40 = (char **)ppcVar7[1];
              }
            }
          }
        }
      }
      if (((cflag & 0x100) == 0) &&
         (iVar11 = (*(code *)PTR_X509_REQ_get_extensions_006a8c9c)(x), iVar11 != 0)) {
        (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sRequested Extensions:\n","");
        iVar3 = 0;
        do {
          iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar11);
          if (iVar5 <= iVar3) {
            (*(code *)PTR_sk_pop_free_006a8158)(iVar11,PTR_X509_EXTENSION_free_006a8268);
            goto LAB_0055962c;
          }
          iVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar11,iVar3);
          iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a4d0,"");
          if (iVar6 < 1) break;
          a = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar5);
          i2a_ASN1_OBJECT(bp,a);
          iVar6 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar5);
          pcVar10 = "";
          if (iVar6 != 0) {
            pcVar10 = "critical";
          }
          iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(bp,": %s\n",pcVar10);
          if (iVar6 < 1) break;
          iVar6 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(bp,iVar5,cflag,0x10);
          iVar3 = iVar3 + 1;
          if (iVar6 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a510,"");
            ASN1_STRING_print(bp,*(ASN1_STRING **)(iVar5 + 8));
          }
          iVar5 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
        } while (0 < iVar5);
      }
      else {
LAB_0055962c:
        if (((cflag & 0x200) != 0) ||
           (iVar11 = X509_signature_print(bp,x->sig_alg,x->signature), iVar11 != 0)) {
          return 1;
        }
      }
    }
  }
LAB_00559684:
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x79,7,"t_req.c",0x103);
  return 0;
}

