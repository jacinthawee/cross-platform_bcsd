
undefined4
unpack_revinfo(int *param_1,undefined4 *param_2,int *param_3,int *param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  
  puVar1 = (undefined *)(*(code *)PTR_BUF_strdup_006a6fdc)(param_5);
  if (puVar1 == (undefined *)0x0) {
    iVar3 = 0;
    iVar9 = 0;
    uVar6 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
    goto joined_r0x00430004;
  }
  puVar2 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar1,0x2c);
  puVar8 = PTR_strchr_006a9a28;
  if (puVar2 == (undefined *)0x0) {
    puVar8 = (undefined *)0x0;
    if (param_1 != (int *)0x0) {
      puVar5 = (undefined *)0x0;
      goto LAB_0042fcf8;
    }
LAB_0042ff44:
    iVar3 = 0;
    iVar9 = 0;
    uVar6 = 0xffffffff;
    goto LAB_0042ff50;
  }
  puVar5 = puVar2 + 1;
  *puVar2 = 0;
  puVar2 = (undefined *)(*(code *)puVar8)(puVar5,0x2c);
  if (puVar2 == (undefined *)0x0) {
    puVar8 = (undefined *)0x0;
  }
  else {
    puVar8 = puVar2 + 1;
    *puVar2 = 0;
  }
  if (param_1 != (int *)0x0) {
LAB_0042fcf8:
    iVar3 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
    *param_1 = iVar3;
    if (iVar3 != 0) {
      iVar3 = (*(code *)PTR_ASN1_UTCTIME_set_string_006a7034)(iVar3,puVar1);
      if (iVar3 != 0) {
        if (puVar5 == (undefined *)0x0) goto LAB_0042ff44;
        goto LAB_0042fd30;
      }
      pcVar4 = "invalid revocation date %s\n";
      puVar5 = puVar1;
LAB_0042fe70:
      iVar3 = 0;
      iVar9 = 0;
      uVar6 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar4,puVar5);
      goto LAB_0042fe8c;
    }
    pcVar4 = "memory allocation failure\n";
    goto LAB_0042ffc0;
  }
LAB_0042fd30:
  iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"unspecified");
  if (iVar3 == 0) {
    uVar6 = 0;
    iVar3 = 0;
    iVar9 = 0;
LAB_0042ff50:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = uVar6;
    }
    if (param_4 == (int *)0x0) {
      uVar6 = 1;
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar3);
    }
    else {
      *param_4 = iVar3;
      uVar6 = 1;
    }
  }
  else {
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"keyCompromise");
    if (iVar3 == 0) {
      uVar6 = 1;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"CACompromise");
    if (iVar3 == 0) {
      uVar6 = 2;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"affiliationChanged");
    if (iVar3 == 0) {
      uVar6 = 3;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"superseded");
    if (iVar3 == 0) {
      uVar6 = 4;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"cessationOfOperation");
    if (iVar3 == 0) {
      uVar6 = 5;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"certificateHold");
    if (iVar3 == 0) {
      uVar6 = 6;
      iVar3 = 0;
      iVar9 = 0;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"removeFromCRL");
    if (iVar3 == 0) {
      iVar3 = 0;
      iVar9 = 0;
      uVar6 = 8;
      goto LAB_0042ff50;
    }
    iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"holdInstruction");
    if (iVar3 == 0) {
      if (puVar8 == (undefined *)0x0) {
        pcVar4 = "missing hold instruction\n";
        goto LAB_0042ffc0;
      }
      iVar9 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar8,0);
      if (iVar9 != 0) {
        if (param_3 == (int *)0x0) {
          iVar3 = 0;
          uVar6 = 6;
        }
        else {
          *param_3 = iVar9;
          iVar3 = 0;
          uVar6 = 6;
        }
        goto LAB_0042ff50;
      }
      iVar3 = 0;
      uVar6 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid object identifier %s\n",puVar8);
    }
    else {
      iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"keyTime");
      if (iVar3 == 0) {
        iVar7 = 9;
      }
      else {
        iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(puVar5,"CAkeyTime");
        if (iVar3 != 0) {
          pcVar4 = "invalid reason code %s\n";
          goto LAB_0042fe70;
        }
        iVar7 = 10;
      }
      if (puVar8 == (undefined *)0x0) {
        pcVar4 = "missing compromised time\n";
LAB_0042ffc0:
        iVar3 = 0;
        iVar9 = 0;
        uVar6 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar4);
      }
      else {
        iVar3 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a703c)();
        if (iVar3 == 0) {
          iVar9 = 0;
          uVar6 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
        }
        else {
          iVar9 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a6ffc)(iVar3,puVar8);
          if (iVar9 != 0) {
            uVar6 = 2;
            iVar9 = 0;
            if (iVar7 == 9) {
              uVar6 = 1;
            }
            goto LAB_0042ff50;
          }
          iVar9 = 0;
          uVar6 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid compromised time %s\n",puVar8);
        }
      }
    }
  }
LAB_0042fe8c:
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
joined_r0x00430004:
  if (param_3 == (int *)0x0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar9);
  }
  if (param_4 == (int *)0x0) {
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar3);
    return uVar6;
  }
  return uVar6;
}

