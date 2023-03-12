
int X509_REQ_print(BIO *bp,X509_REQ *req)

{
  byte bVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  EVP_PKEY *pkey;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  stack_st_X509_EXTENSION *psVar6;
  ASN1_OBJECT *a;
  int iVar7;
  char **ppcVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  X509_REQ_INFO *pXVar12;
  stack_st_X509_ATTRIBUTE *psVar13;
  int local_48;
  char **local_3c;
  char *local_38;
  int local_34;
  
  pXVar12 = req->req_info;
  iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"Certificate Request:\n",0x15);
  if ((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"    Data:\n",10), 0 < iVar2)) {
    pAVar3 = pXVar12->version;
    if (pAVar3->type == 0x102) {
      pcVar11 = "-";
    }
    else {
      pcVar11 = "";
    }
    if (pAVar3->length < 1) {
      iVar2 = 0;
    }
    else {
      pbVar9 = pAVar3->data;
      iVar2 = 0;
      pbVar10 = pbVar9 + pAVar3->length;
      do {
        bVar1 = *pbVar9;
        pbVar9 = pbVar9 + 1;
        iVar2 = (uint)bVar1 + iVar2 * 0x100;
      } while (pbVar10 != pbVar9);
    }
    iVar2 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar11,iVar2,pcVar11,iVar2);
    if (((((0 < iVar2) &&
          (iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"        Subject:%c",0x20), 0 < iVar2)) &&
         (iVar2 = X509_NAME_print_ex(bp,pXVar12->subject,0x10,0), -1 < iVar2)) &&
        ((iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1), 0 < iVar2 &&
         (iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"        Subject Public Key Info:\n",0x21),
         0 < iVar2)))) &&
       ((iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%12sPublic Key Algorithm: ",""), 0 < iVar2
        && ((iVar2 = i2a_ASN1_OBJECT(bp,pXVar12->pubkey->algor->algorithm), 0 < iVar2 &&
            (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(bp,"\n"), 0 < iVar2)))))) {
      pkey = X509_REQ_get_pubkey(req);
      if (pkey == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(bp,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a6e40)(bp);
      }
      else {
        EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pkey);
      }
      iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%8sAttributes:\n","");
      if (0 < iVar2) {
        psVar13 = req->req_info->attributes;
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar13);
        if (iVar2 == 0) {
          iVar2 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%12sa0:00\n","");
          if (iVar2 < 1) goto LAB_00556f78;
        }
        else {
          for (iVar2 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar13), iVar2 < iVar4;
              iVar2 = iVar2 + 1) {
            ppAVar5 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a6e24)(psVar13,iVar2);
            iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*ppAVar5);
            iVar4 = X509_REQ_extension_nid(iVar4);
            if (iVar4 == 0) {
              iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(bp,&DAT_00669a00,"");
              if (iVar4 < 1) goto LAB_00556f78;
              iVar4 = i2a_ASN1_OBJECT(bp,*ppAVar5);
              if (iVar4 < 1) {
                local_48 = 0;
                local_38 = (char *)0x0;
                local_3c = (char **)0x0;
                local_34 = 1;
              }
              else {
                if (ppAVar5[1] == (ASN1_OBJECT *)0x0) {
                  local_34 = (*(code *)PTR_sk_num_006a6e2c)(ppAVar5[2]);
                  local_48 = 0;
                  goto LAB_005572a8;
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
                    iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,&DAT_0063eb84,1);
                    iVar4 = iVar4 + -1;
                    if (iVar7 != 1) goto LAB_00556f78;
                  } while (iVar4 != 0);
                }
                iVar7 = (*(code *)PTR_BIO_puts_006a6f58)(bp,":");
                if (iVar7 < 1) goto LAB_00556f78;
                if ((local_38 + -0x13 < (char *)0x2) || (local_38 == (char *)0x16)) {
                  pcVar11 = (char *)(*(code *)PTR_BIO_write_006a6e14)(bp,local_3c[2],*local_3c);
                  if (pcVar11 != *local_3c) goto LAB_00556f78;
                  (*(code *)PTR_BIO_puts_006a6f58)(bp,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a6f58)(bp,"unable to print attribute\n");
                }
                local_48 = local_48 + 1;
                if (local_34 <= local_48) break;
LAB_005572a8:
                ppcVar8 = (char **)(*(code *)PTR_sk_value_006a6e24)(ppAVar5[2],local_48);
                local_38 = *ppcVar8;
                local_3c = (char **)ppcVar8[1];
              }
            }
          }
        }
        psVar6 = X509_REQ_get_extensions(req);
        if (psVar6 == (stack_st_X509_EXTENSION *)0x0) {
LAB_00557220:
          iVar2 = X509_signature_print(bp,req->sig_alg,req->signature);
          if (iVar2 != 0) {
            return 1;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)(bp,"%8sRequested Extensions:\n","");
          iVar2 = 0;
          do {
            iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
            if (iVar4 <= iVar2) {
              (*(code *)PTR_sk_pop_free_006a7058)(psVar6,PTR_X509_EXTENSION_free_006a7168);
              goto LAB_00557220;
            }
            iVar4 = (*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
            iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,&DAT_00669a00,"");
            if (iVar7 < 1) break;
            a = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a7bb4)(iVar4);
            i2a_ASN1_OBJECT(bp,a);
            iVar7 = (*(code *)PTR_X509_EXTENSION_get_critical_006a8d4c)(iVar4);
            pcVar11 = "";
            if (iVar7 != 0) {
              pcVar11 = "critical";
            }
            iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,": %s\n",pcVar11);
            if (iVar7 < 1) break;
            iVar7 = (*(code *)PTR_X509V3_EXT_print_006a8d50)(bp,iVar4,0,0x10);
            iVar2 = iVar2 + 1;
            if (iVar7 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(bp,&DAT_00669a40,"");
              ASN1_STRING_print(bp,*(ASN1_STRING **)(iVar4 + 8));
            }
            iVar4 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
          } while (0 < iVar4);
        }
      }
    }
  }
LAB_00556f78:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x79,7,"t_req.c",0xf7);
  return 0;
}

