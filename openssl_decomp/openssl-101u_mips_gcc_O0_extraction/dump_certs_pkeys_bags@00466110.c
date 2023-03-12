
undefined4
dump_certs_pkeys_bags
          (undefined4 param_1,char **param_2,char **param_3,char **param_4,uint param_5,
          undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char **ppcVar10;
  undefined4 *puVar11;
  char **ppcVar12;
  undefined4 uVar13;
  char **ppcVar14;
  char *local_5c;
  char *local_40;
  char *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar7 = param_5 & 4;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar14 = (char **)0x0;
  local_5c = "Bag Attributes";
  local_40 = "%s, Iteration %ld\n";
  pcVar9 = (char *)param_2;
  ppcVar10 = param_3;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
  if (0 < iVar3) {
    do {
      pcVar9 = (char *)ppcVar14;
      puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_2);
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar4);
      puVar1 = PTR_bio_err_006a6e3c;
      if (iVar3 == 0x97) {
        if (uVar7 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"Shrouded Keybag: ");
          pcVar9 = (char *)&local_30;
          puVar11 = *(undefined4 **)puVar4[1];
          ppcVar10 = *(char ***)(puVar11[1] + 4);
          local_30 = ppcVar10[2];
          ppcVar10 = (char **)*ppcVar10;
          iVar3 = (*(code *)PTR_d2i_PBEPARAM_006a7204)(0);
          if (iVar3 != 0) {
            uVar8 = *(undefined4 *)puVar1;
            uVar13 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar11);
            ppcVar10 = (char **)(*(code *)PTR_OBJ_nid2ln_006a711c)(uVar13);
            uVar13 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*(undefined4 *)(iVar3 + 4));
            pcVar9 = local_40;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar8,"%s, Iteration %ld\n",ppcVar10,uVar13);
            (*(code *)PTR_PBEPARAM_free_006a720c)(iVar3);
          }
        }
        if ((param_5 & 1) == 0) {
          print_attribs(param_1,puVar4[2],"Bag Attributes");
          pcVar9 = (char *)param_3;
          ppcVar10 = param_4;
          iVar3 = (*(code *)PTR_PKCS12_decrypt_skey_006a7228)(puVar4);
          if (iVar3 != 0) {
            ppcVar12 = (char **)(*(code *)PTR_EVP_PKCS82PKEY_006a7220)(iVar3);
            if (ppcVar12 != (char **)0x0) {
              print_attribs(param_1,*(undefined4 *)(iVar3 + 0x10),"Key Attributes");
              (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a722c)(iVar3);
              ppcVar10 = *(char ***)PTR_enc_006a7224;
              pcVar9 = (char *)ppcVar12;
              (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)
                        (param_1,ppcVar12,ppcVar10,0,0,0,param_6);
              (*(code *)PTR_EVP_PKEY_free_006a6e78)(ppcVar12);
              goto LAB_004662c4;
            }
            (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a722c)(iVar3);
          }
LAB_00466570:
          uVar13 = 0;
          goto LAB_00466574;
        }
      }
      else if (iVar3 < 0x98) {
        if (iVar3 == 0x96) {
          if (uVar7 != 0) {
            pcVar9 = "Key bag\n";
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
          }
          if ((param_5 & 1) == 0) {
            pcVar9 = (char *)puVar4[2];
            ppcVar10 = (char **)local_5c;
            print_attribs(param_1);
            iVar3 = puVar4[1];
            ppcVar12 = (char **)(*(code *)PTR_EVP_PKCS82PKEY_006a7220)(iVar3);
            if (ppcVar12 == (char **)0x0) goto LAB_00466570;
            print_attribs(param_1,*(undefined4 *)(iVar3 + 0x10),"Key Attributes");
            ppcVar10 = *(char ***)PTR_enc_006a7224;
            pcVar9 = (char *)ppcVar12;
            (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)
                      (param_1,ppcVar12,ppcVar10,0,0,0,param_6);
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(ppcVar12);
          }
        }
        else {
LAB_00466448:
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"Warning unsupported bag type: ");
          (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(*(undefined4 *)puVar1,*puVar4);
          pcVar9 = "\n";
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1);
        }
      }
      else if (iVar3 == 0x98) {
        if (uVar7 != 0) {
          pcVar9 = "Certificate bag\n";
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        }
        if ((param_5 & 2) == 0) {
          pcVar9 = (char *)0x9d;
          iVar3 = (*(code *)PTR_PKCS12_get_attr_gen_006a7214)(puVar4[2]);
          uVar6 = param_5 & 8;
          if (iVar3 != 0) {
            uVar6 = param_5 & 0x10;
          }
          if (uVar6 == 0) {
            pcVar9 = (char *)puVar4[2];
            ppcVar10 = (char **)local_5c;
            print_attribs(param_1);
            iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)puVar4[1]);
            if (iVar3 == 0x9e) {
              ppcVar12 = (char **)(*(code *)PTR_PKCS12_certbag2x509_006a7218)(puVar4);
              if (ppcVar12 == (char **)0x0) goto LAB_00466570;
              dump_cert_text(param_1,ppcVar12);
              pcVar9 = (char *)ppcVar12;
              (*(code *)PTR_PEM_write_bio_X509_006a6f20)(param_1);
              (*(code *)PTR_X509_free_006a6e90)(ppcVar12);
            }
          }
        }
      }
      else {
        if (iVar3 != 0x9b) goto LAB_00466448;
        if (uVar7 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"Safe Contents bag\n");
        }
        pcVar9 = (char *)puVar4[2];
        ppcVar10 = (char **)local_5c;
        print_attribs(param_1);
        uVar13 = puVar4[1];
        for (iVar3 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar13), iVar3 < iVar5;
            iVar3 = iVar3 + 1) {
          pcVar9 = (char *)(*(code *)PTR_sk_value_006a6e24)(uVar13,iVar3);
          ppcVar10 = param_3;
          iVar5 = dump_certs_pkeys_bag(param_1,pcVar9,param_3,param_4,param_5,param_6);
          if (iVar5 == 0) goto LAB_00466570;
        }
      }
LAB_004662c4:
      ppcVar14 = (char **)((int)ppcVar14 + 1);
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
    } while ((int)ppcVar14 < iVar3);
  }
  uVar13 = 1;
LAB_00466574:
  if (local_2c != *(int *)puVar2) {
    iVar3 = local_2c;
    uVar13 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (0 < (int)ppcVar10) {
      ppcVar14 = (char **)pcVar9;
      do {
        ppcVar12 = (char **)((int)ppcVar14 + 1);
        uVar13 = (*(code *)PTR_BIO_printf_006a6e38)(iVar3,"%02X ",*(char *)ppcVar14);
        ppcVar14 = ppcVar12;
      } while (ppcVar12 != (char **)((int)pcVar9 + (int)ppcVar10));
    }
    return uVar13;
  }
  return uVar13;
}

