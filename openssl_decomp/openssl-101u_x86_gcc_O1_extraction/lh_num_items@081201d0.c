
ulong lh_num_items(_LHASH *lh)

{
  if (lh != (_LHASH *)0x0) {
    return lh->num_items;
  }
  return 0;
}

