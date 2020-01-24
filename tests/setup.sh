touch \
    file \
    perms_exec_all \
    perms_exec_u \
    perms_exec_g \
    perms_exec_o \
    perms_exec_ug \
    perms_suid \
    perms_suid_exec \
    perms_suid_exec_all \
    perms_sgid \
    perms_sgid_exec \
    perms_sgid_exec_all \
    perms_sticky \
    perms_sticky_exec \
    perms_sticky_exec_all \

chmod +x    perms_exec_all
chmod u+x   perms_exec_u
chmod g+x   perms_exec_g
chmod o+x   perms_exec_o
chmod ug+x  perms_exec_ug

chmod u+s   perms_suid
chmod u+sx  perms_suid_exec     perms_suid_exec_all
chmod +x    perms_suid_exec_all

chmod g+s   perms_sgid
chmod g+sx  perms_sgid_exec     perms_sgid_exec_all
chmod +x    perms_sgid_exec_all

chmod +t    perms_sticky        perms_sticky_exec       perms_sticky_exec_all
chmod o+x   perms_sticky_exec
chmod +x    perms_sticky_exec_all

mkdir \
    dir \
    dir_gw_nosticky \
    dir_gw_nostickynoexec \
    dir_gw_sticky \
    dir_gw_stickynoexec \
    dirmore \
    errs

    # force o+rwx
chmod 557       dir_gw_nosticky         dir_gw_sticky
    # force o+rw
chmod 756       dir_gw_nostickynoexec   dir_gw_stickynoexec
chmod +t        dir_gw_sticky           dir_gw_stickynoexec

ln -s file  symlink
ln -s file_ symlink_invalid

mkfifo fifo

python -c "import socket as s;k=s.socket(s.AF_UNIX);k.bind('socket')"

echo -n "Have sudo access (y\n): "
read -n1 ANS
echo
if [ $ANS == 'y' ]; then
    sudo mknod cnod c 127 127
    sudo mknod bnod b 127 127
fi

# extended attributes and ACLs
touch \
    x_acls \
    x_attrs \
    x_attrs_acls
echo "test text" > x_acls

if [ $(uname) == 'Darwin' ]; then
    # XATTR:
    xattr -w com.apple.metadata 0       x_attrs x_attrs_acls
    # ACL:
    chmod +a "group:_guest deny read"   x_acls  x_attrs_acls
fi

# error handling
mkdir \
    errs/1 \
    errs/2 \
    errs/3

touch errs/1/file{1..5}
touch errs/2/file{1..5}
touch errs/3/file{1..5}

chmod 311 errs/1
chmod 644 errs/2
chmod 755 errs/3

# recursive stuff
mkdir -p "dirmore/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp"
touch "dirmore/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp/tmp/test"

touch dirmore/tmp{1..9}
touch dirmore/tmp{10..99}
touch dirmore/tmp100
