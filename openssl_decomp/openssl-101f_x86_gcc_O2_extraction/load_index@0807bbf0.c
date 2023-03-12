
undefined4 * load_index(char *param_1,undefined4 *param_2)

{
  char cVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  TXT_DB *db;
  CONF *conf;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  CONF *conf_00;
  int in_GS_OFFSET;
  int local_124;
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  local_124 = -1;
  if (bp == (BIO *)0x0) {
    puVar4 = (undefined4 *)0x0;
    ERR_print_errors(bio_err);
    goto LAB_0807bd3a;
  }
  lVar2 = BIO_ctrl(bp,0x6c,3,param_1);
  if (lVar2 < 1) {
    puVar4 = (undefined4 *)0x0;
    perror(param_1);
    BIO_printf(bio_err,"unable to open \'%s\'\n",param_1);
  }
  else {
    db = TXT_DB_read(bp,6);
    if (db != (TXT_DB *)0x0) {
      BIO_snprintf(local_120,0x100,"%s.attr",param_1);
      conf = NCONF_new((CONF_METHOD *)0x0);
      iVar3 = NCONF_load(conf,local_120,&local_124);
      conf_00 = conf;
      if (iVar3 < 1) {
        if (local_124 < 1) {
          conf_00 = (CONF *)0x0;
          NCONF_free(conf);
          goto LAB_0807bca9;
        }
        BIO_printf(bio_err,"error on line %ld of db attribute file \'%s\'\n",local_124,local_120);
      }
      else {
LAB_0807bca9:
        puVar4 = (undefined4 *)CRYPTO_malloc(8,"apps.c",0x731);
        if (puVar4 != (undefined4 *)0x0) {
          puVar4[1] = db;
          if (param_2 == (undefined4 *)0x0) {
            *puVar4 = 1;
          }
          else {
            *puVar4 = *param_2;
          }
          if (conf_00 == (CONF *)0x0) goto LAB_0807bd2e;
          pcVar5 = NCONF_get_string(conf_00,(char *)0x0,"unique_subject");
          if (pcVar5 != (char *)0x0) {
            cVar1 = *pcVar5;
            if (cVar1 == 'N') {
LAB_0807bdc4:
              uVar6 = 0;
            }
            else {
              if (cVar1 < 'O') {
                if ((cVar1 == '0') || (cVar1 == 'F')) goto LAB_0807bdc4;
              }
              else if ((cVar1 == 'f') || (cVar1 == 'n')) goto LAB_0807bdc4;
              uVar6 = 1;
            }
            *puVar4 = uVar6;
          }
          NCONF_free(conf_00);
          goto LAB_0807bd2e;
        }
        fwrite("Out of memory\n",1,0xe,stderr);
        conf = conf_00;
      }
      if (conf != (CONF *)0x0) {
        NCONF_free(conf);
      }
      TXT_DB_free(db);
    }
    puVar4 = (undefined4 *)0x0;
  }
LAB_0807bd2e:
  BIO_free_all(bp);
LAB_0807bd3a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

