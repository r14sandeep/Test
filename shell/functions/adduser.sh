#!/bin/sh
add_a_user()
{
	USER=$1
	PASSWORD=$2
	shift;shift;
	COMMENTS=$@
	echo "$COMMENTS"
	echo "adding user $USER"
	echo useradd -c "$COMMENTS" $USER
	echo passwd $USER $PASSWORD
	echo "added user $USER ($COMMENTS) with pass $PASSWORD"
}
echo "start of script"
add_a_user sandeep 123 engineer
add_a_user deepu badpassword the singer
add_a_user qwerty worsepassword the role model
echo "End of script..."
