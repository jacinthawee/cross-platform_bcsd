
int asn1_bio_write(BIO *param_1,void *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint len;
  int in_GS_OFFSET;
  int local_34;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((param_2 == (void *)0x0) || ((int)param_3 < 0)) || (param_1->next_bio == (bio_st *)0x0)) ||
     (puVar2 = (uint *)param_1->ptr, puVar2 == (uint *)0x0)) {
    iVar5 = 0;
LAB_081e54c2:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar5;
  }
  uVar4 = *puVar2;
  local_34 = 0;
LAB_081e54ac:
  if (uVar4 < 5) {
    do {
      switch((&switchD_081e54b5::switchdataD_0823e988)[uVar4]) {
      case (undefined *)0x81e54e0:
        iVar5 = ASN1_object_size(0,param_3,puVar2[7]);
        puVar2[4] = iVar5 - param_3;
        if ((int)puVar2[2] < (int)(iVar5 - param_3)) {
          OpenSSLDie("bio_asn1.c",0xe8,"ctx->buflen <= ctx->bufsize");
        }
        local_24 = (uchar *)puVar2[1];
        ASN1_put_object(&local_24,0,param_3,puVar2[7],puVar2[6]);
        puVar2[5] = param_3;
        *puVar2 = 3;
      case (undefined *)0x81e5529:
        iVar5 = BIO_write(param_1->next_bio,(void *)(puVar2[3] + puVar2[1]),puVar2[4]);
        if (iVar5 < 1) {
LAB_081e55bd:
          BIO_clear_flags(param_1,0xf);
          BIO_copy_next_retry(param_1);
          if (local_34 != 0) {
LAB_081e55e7:
            iVar5 = local_34;
          }
          goto LAB_081e54c2;
        }
        puVar1 = puVar2 + 4;
        *puVar1 = *puVar1 - iVar5;
        if (*puVar1 == 0) {
          puVar2[3] = 0;
          *puVar2 = 4;
switchD_081e54b5_caseD_81e563e:
          uVar4 = puVar2[5];
          if ((int)param_3 <= (int)puVar2[5]) {
            uVar4 = param_3;
          }
          iVar5 = BIO_write(param_1->next_bio,param_2,uVar4);
          if (0 < iVar5) {
            uVar4 = puVar2[5];
            local_34 = local_34 + iVar5;
            param_2 = (void *)((int)param_2 + iVar5);
            param_3 = param_3 - iVar5;
            puVar2[5] = uVar4 - iVar5;
            if (uVar4 - iVar5 == 0) {
              *puVar2 = 2;
            }
            if (param_3 == 0) {
              BIO_clear_flags(param_1,0xf);
              BIO_copy_next_retry(param_1);
              goto LAB_081e55e7;
            }
          }
          uVar4 = *puVar2;
          goto LAB_081e54ac;
        }
        puVar2[3] = puVar2[3] + iVar5;
        uVar4 = *puVar2;
        if (4 < uVar4) goto LAB_081e5560;
        break;
      case (undefined *)0x81e5578:
        len = puVar2[0xd];
        pcVar3 = (code *)puVar2[9];
        if ((int)len < 1) goto LAB_081e54ac;
        uVar4 = puVar2[0xe];
        while( true ) {
          iVar5 = BIO_write(param_1->next_bio,(void *)(uVar4 + puVar2[0xc]),len);
          if (iVar5 < 1) goto LAB_081e55bd;
          len = puVar2[0xd] - iVar5;
          puVar2[0xd] = len;
          if ((int)len < 1) break;
          uVar4 = iVar5 + puVar2[0xe];
          puVar2[0xe] = uVar4;
        }
        if (pcVar3 != (code *)0x0) {
          (*pcVar3)(param_1,puVar2 + 0xc,puVar2 + 0xd,puVar2 + 0xf);
        }
        *puVar2 = 2;
        puVar2[0xe] = 0;
        uVar4 = 2;
        break;
      case (undefined *)0x81e55f0:
        goto switchD_081e54b5_caseD_81e55f0;
      case (undefined *)0x81e563e:
        goto switchD_081e54b5_caseD_81e563e;
      }
    } while( true );
  }
LAB_081e5560:
  BIO_clear_flags(param_1,0xf);
  iVar5 = 0;
  goto LAB_081e54c2;
switchD_081e54b5_caseD_81e55f0:
  if (((code *)puVar2[8] != (code *)0x0) &&
     (iVar5 = (*(code *)puVar2[8])(param_1,puVar2 + 0xc,puVar2 + 0xd,puVar2 + 0xf), iVar5 == 0)) {
    BIO_clear_flags(param_1,0xf);
    goto LAB_081e54c2;
  }
  uVar4 = ((int)puVar2[0xd] < 1) + 1;
  *puVar2 = uVar4;
  goto LAB_081e54ac;
}

