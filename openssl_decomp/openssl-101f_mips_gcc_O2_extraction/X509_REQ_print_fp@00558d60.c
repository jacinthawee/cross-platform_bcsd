
int X509_REQ_print_fp(FILE *bp,X509_REQ *req)

{
  byte bVar1;
  undefined4 uVar2;
  BIO *out;
  int iVar3;
  ASN1_INTEGER *pAVar4;
  EVP_PKEY *pkey;
  int iVar5;
  ASN1_OBJECT **ppAVar6;
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
  
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  out = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (out == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7a,7,"t_req.c",0x51);
    return 0;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(out,0x6a,0,bp);
  pXVar13 = req->req_info;
  iVar3 = (*(code *)PTR_BIO_write_006a7f14)(out,"Certificate Request:\n",0x15);
  if ((0 < iVar3) && (iVar3 = (*(code *)PTR_BIO_write_006a7f14)(out,"    Data:\n",10), 0 < iVar3)) {
    pAVar4 = pXVar13->version;
    if (pAVar4->type == 0x102) {
      pcVar12 = "-";
    }
    else {
      pcVar12 = "";
    }
    if (pAVar4->length < 1) {
      iVar3 = 0;
    }
    else {
      pbVar10 = pAVar4->data;
      iVar3 = 0;
      pbVar11 = pbVar10 + pAVar4->length;
      do {
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        iVar3 = (uint)bVar1 + iVar3 * 0x100;
      } while (pbVar11 != pbVar10);
    }
    iVar3 = (*(code *)PTR_BIO_printf_006a7f38)
                      (out,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar12,iVar3,pcVar12,iVar3);
    if (((((0 < iVar3) &&
          (iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(out,"        Subject:%c",0x20), 0 < iVar3)) &&
         (iVar3 = X509_NAME_print_ex(out,pXVar13->subject,0x10,0), -1 < iVar3)) &&
        ((iVar3 = (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1), 0 < iVar3 &&
         (iVar3 = (*(code *)PTR_BIO_write_006a7f14)(out,"        Subject Public Key Info:\n",0x21),
         0 < iVar3)))) &&
       ((iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sPublic Key Algorithm: ",""), 0 < iVar3
        && ((iVar3 = i2a_ASN1_OBJECT(out,pXVar13->pubkey->algor->algorithm), 0 < iVar3 &&
            (iVar3 = (*(code *)PTR_BIO_puts_006a8058)(out,"\n"), 0 < iVar3)))))) {
      pkey = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(req);
      if (pkey == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a7f40)(out);
      }
      else {
        EVP_PKEY_print_public(out,pkey,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pkey);
      }
      iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%8sAttributes:\n","");
      if (0 < iVar3) {
        psVar14 = req->req_info->attributes;
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar14);
        if (iVar3 == 0) {
          iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sa0:00\n","");
          if (iVar3 < 1) goto LAB_005590a0;
        }
        else {
          for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar14), iVar3 < iVar5;
              iVar3 = iVar3 + 1) {
            ppAVar6 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a7f24)(psVar14,iVar3);
            uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*ppAVar6);
            iVar5 = (*(code *)PTR_X509_REQ_extension_nid_006a9e68)(uVar2);
            if (iVar5 == 0) {
              iVar5 = (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a4d0,"");
              if (iVar5 < 1) goto LAB_005590a0;
              iVar5 = i2a_ASN1_OBJECT(out,*ppAVar6);
              if (iVar5 < 1) {
                local_48 = 0;
                local_38 = (char *)0x0;
                local_3c = (char **)0x0;
                local_34 = 1;
              }
              else {
                if (ppAVar6[1] == (ASN1_OBJECT *)0x0) {
                  local_34 = (*(code *)PTR_sk_num_006a7f2c)(ppAVar6[2]);
                  local_48 = 0;
                  goto LAB_00559440;
                }
                local_48 = 0;
                local_34 = 1;
                local_38 = ppAVar6[2]->sn;
                local_3c = ppAVar6[2]->ln;
              }
              while( true ) {
                iVar5 = 0x19 - iVar5;
                if (0 < iVar5) {
                  do {
                    iVar8 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0063f0b8,1);
                    iVar5 = iVar5 + -1;
                    if (iVar8 != 1) goto LAB_005590a0;
                  } while (iVar5 != 0);
                }
                iVar8 = (*(code *)PTR_BIO_puts_006a8058)(out,":");
                if (iVar8 < 1) goto LAB_005590a0;
                if ((local_38 + -0x13 < (char *)0x2) || (local_38 == (char *)0x16)) {
                  pcVar12 = (char *)(*(code *)PTR_BIO_write_006a7f14)(out,local_3c[2],*local_3c);
                  if (pcVar12 != *local_3c) goto LAB_005590a0;
                  (*(code *)PTR_BIO_puts_006a8058)(out,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a8058)(out,"unable to print attribute\n");
                }
                local_48 = local_48 + 1;
                if (local_34 <= local_48) break;
LAB_00559440:
                ppcVar9 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppAVar6[2],local_48);
                local_38 = *ppcVar9;
                local_3c = (char **)ppcVar9[1];
              }
            }
          }
        }
        iVar3 = (*(code *)PTR_X509_REQ_get_extensions_006a8c9c)(req);
        if (iVar3 == 0) {
LAB_005593b0:
          iVar3 = X509_signature_print(out,req->sig_alg,req->signature);
          if (iVar3 != 0) {
            iVar3 = 1;
            goto LAB_005590c8;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(out,"%8sRequested Extensions:\n","");
          iVar5 = 0;
          do {
            iVar8 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
            if (iVar8 <= iVar5) {
              (*(code *)PTR_sk_pop_free_006a8158)(iVar3,PTR_X509_EXTENSION_free_006a8268);
              goto LAB_005593b0;
            }
            iVar8 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar5);
            iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a4d0,"");
            if (iVar7 < 1) break;
            a = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar8);
            i2a_ASN1_OBJECT(out,a);
            iVar7 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar8);
            pcVar12 = "";
            if (iVar7 != 0) {
              pcVar12 = "critical";
            }
            iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(out,": %s\n",pcVar12);
            if (iVar7 < 1) break;
            iVar7 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(out,iVar8,0,0x10);
            iVar5 = iVar5 + 1;
            if (iVar7 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a510,"");
              ASN1_STRING_print(out,*(ASN1_STRING **)(iVar8 + 8));
            }
            iVar8 = (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1);
          } while (0 < iVar8);
        }
      }
    }
  }
LAB_005590a0:
  iVar3 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x79,7,"t_req.c",0x103);
LAB_005590c8:
  (*(code *)PTR_BIO_free_006a7f70)(out);
  return iVar3;
}

