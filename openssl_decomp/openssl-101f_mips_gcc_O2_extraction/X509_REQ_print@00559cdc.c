
int X509_REQ_print(BIO *bp,X509_REQ *req)

{
  byte bVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  EVP_PKEY *pkey;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  undefined4 uVar6;
  int iVar7;
  ASN1_OBJECT *a;
  int iVar8;
  char **ppcVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *pcVar12;
  X509_REQ_INFO *pXVar13;
  stack_st_X509_ATTRIBUTE *psVar14;
  int local_48;
  char **local_3c;
  char *local_38;
  int local_34;
  
  pXVar13 = req->req_info;
  iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"Certificate Request:\n",0x15);
  if ((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"    Data:\n",10), 0 < iVar2)) {
    pAVar3 = pXVar13->version;
    if (pAVar3->type == 0x102) {
      pcVar12 = "-";
    }
    else {
      pcVar12 = "";
    }
    if (pAVar3->length < 1) {
      iVar2 = 0;
    }
    else {
      pbVar10 = pAVar3->data;
      iVar2 = 0;
      pbVar11 = pbVar10 + pAVar3->length;
      do {
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        iVar2 = (uint)bVar1 + iVar2 * 0x100;
      } while (pbVar11 != pbVar10);
    }
    iVar2 = (*(code *)PTR_BIO_printf_006a7f38)
                      (bp,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar12,iVar2,pcVar12,iVar2);
    if (((((0 < iVar2) &&
          (iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"        Subject:%c",0x20), 0 < iVar2)) &&
         (iVar2 = X509_NAME_print_ex(bp,pXVar13->subject,0x10,0), -1 < iVar2)) &&
        ((iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1), 0 < iVar2 &&
         (iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp,"        Subject Public Key Info:\n",0x21),
         0 < iVar2)))) &&
       ((iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sPublic Key Algorithm: ",""), 0 < iVar2
        && ((iVar2 = i2a_ASN1_OBJECT(bp,pXVar13->pubkey->algor->algorithm), 0 < iVar2 &&
            (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(bp,"\n"), 0 < iVar2)))))) {
      pkey = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(req);
      if (pkey == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a7f40)(bp);
      }
      else {
        EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pkey);
      }
      iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sAttributes:\n","");
      if (0 < iVar2) {
        psVar14 = req->req_info->attributes;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar14);
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%12sa0:00\n","");
          if (iVar2 < 1) goto LAB_00559fd8;
        }
        else {
          for (iVar2 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar14), iVar2 < iVar4;
              iVar2 = iVar2 + 1) {
            ppAVar5 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a7f24)(psVar14,iVar2);
            uVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*ppAVar5);
            iVar4 = (*(code *)PTR_X509_REQ_extension_nid_006a9e68)(uVar6);
            if (iVar4 == 0) {
              iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a4d0,"");
              if (iVar4 < 1) goto LAB_00559fd8;
              iVar4 = i2a_ASN1_OBJECT(bp,*ppAVar5);
              if (iVar4 < 1) {
                local_48 = 0;
                local_38 = (char *)0x0;
                local_3c = (char **)0x0;
                local_34 = 1;
              }
              else {
                if (ppAVar5[1] == (ASN1_OBJECT *)0x0) {
                  local_34 = (*(code *)PTR_sk_num_006a7f2c)(ppAVar5[2]);
                  local_48 = 0;
                  goto LAB_0055a308;
                }
                local_48 = 0;
                local_34 = 1;
                local_38 = ppAVar5[2]->sn;
                local_3c = ppAVar5[2]->ln;
              }
              while( true ) {
                iVar4 = 0x19 - iVar4;
                if (0 < iVar4) {
                  do {
                    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp,&DAT_0063f0b8,1);
                    iVar4 = iVar4 + -1;
                    if (iVar8 != 1) goto LAB_00559fd8;
                  } while (iVar4 != 0);
                }
                iVar8 = (*(code *)PTR_BIO_puts_006a8058)(bp,":");
                if (iVar8 < 1) goto LAB_00559fd8;
                if ((local_38 + -0x13 < (char *)0x2) || (local_38 == (char *)0x16)) {
                  pcVar12 = (char *)(*(code *)PTR_BIO_write_006a7f14)(bp,local_3c[2],*local_3c);
                  if (pcVar12 != *local_3c) goto LAB_00559fd8;
                  (*(code *)PTR_BIO_puts_006a8058)(bp,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a8058)(bp,"unable to print attribute\n");
                }
                local_48 = local_48 + 1;
                if (local_34 <= local_48) break;
LAB_0055a308:
                ppcVar9 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppAVar5[2],local_48);
                local_38 = *ppcVar9;
                local_3c = (char **)ppcVar9[1];
              }
            }
          }
        }
        iVar2 = (*(code *)PTR_X509_REQ_get_extensions_006a8c9c)(req);
        if (iVar2 == 0) {
LAB_0055a280:
          iVar2 = X509_signature_print(bp,req->sig_alg,req->signature);
          if (iVar2 != 0) {
            return 1;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sRequested Extensions:\n","");
          iVar4 = 0;
          do {
            iVar8 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
            if (iVar8 <= iVar4) {
              (*(code *)PTR_sk_pop_free_006a8158)(iVar2,PTR_X509_EXTENSION_free_006a8268);
              goto LAB_0055a280;
            }
            iVar8 = (*(code *)PTR_sk_value_006a7f24)(iVar2,iVar4);
            iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a4d0,"");
            if (iVar7 < 1) break;
            a = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar8);
            i2a_ASN1_OBJECT(bp,a);
            iVar7 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar8);
            pcVar12 = "";
            if (iVar7 != 0) {
              pcVar12 = "critical";
            }
            iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,": %s\n",pcVar12);
            if (iVar7 < 1) break;
            iVar7 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(bp,iVar8,0,0x10);
            iVar4 = iVar4 + 1;
            if (iVar7 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_0066a510,"");
              ASN1_STRING_print(bp,*(ASN1_STRING **)(iVar8 + 8));
            }
            iVar8 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
          } while (0 < iVar8);
        }
      }
    }
  }
LAB_00559fd8:
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x79,7,"t_req.c",0x103);
  return 0;
}

