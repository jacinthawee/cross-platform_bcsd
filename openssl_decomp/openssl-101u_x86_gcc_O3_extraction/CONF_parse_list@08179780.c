
int CONF_parse_list(char *list,int sep,int nospc,list_cb *list_cb,void *arg)

{
  byte bVar1;
  ushort **ppuVar2;
  byte *pbVar3;
  int iVar4;
  size_t sVar5;
  byte *pbVar6;
  
  if (list == (char *)0x0) {
    ERR_put_error(0xe,0x77,0x73,"conf_mod.c",0x237);
    return 0;
  }
  do {
    if (nospc == 0) {
LAB_081797d9:
      pbVar3 = (byte *)strchr(list,sep);
      if (((byte *)list == pbVar3) || (*list == 0)) goto LAB_0817985a;
      if (pbVar3 == (byte *)0x0) {
        sVar5 = strlen(list);
        pbVar6 = (byte *)list + (sVar5 - 1);
      }
      else {
        pbVar6 = pbVar3 + -1;
      }
      if (nospc != 0) {
        ppuVar2 = __ctype_b_loc();
        while ((*(byte *)((int)*ppuVar2 + (uint)*pbVar6 * 2 + 1) & 0x20) != 0) {
          pbVar6 = pbVar6 + -1;
        }
      }
      iVar4 = (*list_cb)(list,(int)(pbVar6 + (1 - (int)list)),arg);
    }
    else {
      bVar1 = *list;
      if (bVar1 != 0) {
        ppuVar2 = __ctype_b_loc();
        do {
          if ((*(byte *)((int)*ppuVar2 + (uint)bVar1 * 2 + 1) & 0x20) == 0) goto LAB_081797d9;
          list = (char *)((byte *)list + 1);
          bVar1 = *list;
        } while (bVar1 != 0);
      }
      pbVar3 = (byte *)strchr(list,sep);
LAB_0817985a:
      iVar4 = (*list_cb)((char *)0x0,0,arg);
    }
    if (iVar4 < 1) {
      return iVar4;
    }
    if (pbVar3 == (byte *)0x0) {
      return 1;
    }
    list = (char *)(pbVar3 + 1);
  } while( true );
}

