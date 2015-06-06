# httpbl_manager
----------------
Entity management and admin UI extension for http:BL.

This is a Drupal 7 module for extending the capabilities of the httpbl module (aka http:BL), found on Drupal.org, classified under Spam Control.  

http:BL works quietly in the background by referencing honeypot.org to determine whether visitors to your site should be white or grey or blacklisted (and blocked) from future visits to your site.  Other than a basic configuration page, httpl has no UI.  You cannot use it to add / change / delete the IP addresses it has cached in its own table for faster local reference, so that it does not have to reference honeypot.org for repeated visits from the same user.

http:BL Manager provides that admin UI for managing those cached IP entries.


Requirements
------------
To use this module you must have the following modules:

httpbl - main module that references honeypot.org 

entity - Entity API

views_bulk_operations - (requires Views)

There is no reason to use this module if you do not already have httpbl.  The best use case is if you've used httpbl for some time, and already have a table full of cached IP addresses that you would like to manage, but you don't have direct access to the database.

If you don't already have httpbl, you should start with and get comfortable with that module and how it works on its own.  Then use this module later when there is data to manage.

What httpbl_manager does
------------------------

Upon installation, httpbl_manager makes some schema alterations to the httpbl table that is created by the httpbl module.  On its own, the table used by httpbl to cache IP addresses has no unique identifiers other than the cached IP addresses (alpha-numberic) themselves.

http:BL Manager adds an auto-incrementing entity id (httpbl_id) and a type column so that Drupal can treat these stored IP addresses as managed entities.

It also adds columns for created/modified dates and the uid of the user who manually made changes.  However, these columns are not used by httpbl, so they will only be updated when there has been human intervention.

Finally, there is a notes column (domain) that can used to store miscellaneous information about a cached IP, to help you more easily identify who it belongs to and why you have made changes.

http:BL Manager provides a basic admin UI, using VBO (views_bulk_operations), to provide you with access to see the cached (now managed) IPs and make some changes.

Some changes you can make are:

Extend the expiration date for a managed IP.  This is the date that httpbl uses to automatically remove expired IPs (with cron).

Change the listing status of a managed IP.  For instance, you can whitelist a previously grey-listed IP, or vice-versa.

Add notation to help remind yourself of why you made changes.

Remove a managed IP (this functionality may be changed or removed, however).

What httpbl_manager doesn't do
-------------------------------

http:BL Manager does NOT allow you to add your own IPs to the httpbl table.

http:BL Manager does NOT allow you to permanently whitelist, greylist or blacklist anyone.  However, you can effectively do this by extending the expiration dates for a long time, if you believe that's a good idea.  Personally, this module's creator and the maintainer of the httpbl module believes you are better off letting httpbl maintain those IPs for you, based on the information about them found on honeypot.org.  After all, that is the primary function of httpbl.  It is not intended for self management.

It is understood that sometimes the information at honeypot.org may be disagreeable with an important client or a friend.  The ownership of IP addresses can change.  Good people and organizations can become stuck with a previously used IP address that has a notorious reputation for spam and spam harvesting, so they get blocked from your site and get angry about it because that reputation is beyond their control (and they expect you to do something about that).  If you know and trust those visitors, you can use this module to stop blocking them from your site.

Likewise, however, previously well behaved IP addresses can switch ownership to users with evil intentions.

http:BL Manager is NOT intended to replace httpbl, but exists to help you manage the exceptions to the rule, and nothing is done with permanency, so that httpbl can continue to update the status of its cached IPs, as information on honeypot.org is updated.

The more you manage the IPs on your own, it compromises the trustworthiness of httpbl.  You're really better off letting it manage those IPs itself, however... 

What httpbl_manager may do
--------------------------

On its own, and because httpbl uses no unique identifiers besides the IP addresses it stores, it has been reported to experience problems when duplicate records are attempted to be created, particularly if a site is being heavily and repeatedly bombarded by the same bad IPs.

Since httpbl_manager adds a separate unique, primary key for each record, it's possible (but no promises are made or implied) that it may mitigate this problem to some extent, just by being installed, even if it is rarely used for the UI functions.

That is speculation at this point, as the module is new and has not been heavily used in production environments.

Installation
------------

Just enable the module and it will make the changes to httpbl described above.

De-Installation
---------------
If you decide to uninstall httpbl_manager, you can disable it without full uninstalling, to keep the database changes it made.  If completely uninstalled it will remove those changes and restore the httpbl table to its original columns configuration.

It's possible this could cause a problem if there have been duplicate IPs stored, since they previously had a separate unique identifier that will be removed when un-installed.  This requires further review and testing. 


