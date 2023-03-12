
char * DSO_get_loaded_filename(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    return dso->loaded_filename;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x80,0x43,"dso_lib.c",0x1c7);
  return (char *)0x0;
}

