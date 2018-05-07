using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InteractToken : MonoBehaviour
{
	public Camera unitCamera;
	public GameObject devPointer;
	private GameObject selectedObject;

	void Start ()
	{
		selectedObject = null;
	}
	
	void Update ()
	{
		if (Input.GetMouseButtonDown(0))
		{
			Ray ray = unitCamera.ScreenPointToRay(new Vector3(Input.mousePosition.x, Input.mousePosition.y, 0));
			LayerMask selectionMask = 1 << 8;
			RaycastHit hitObject = new RaycastHit();
			if (Physics.Raycast(ray, out hitObject, 1000f, selectionMask))
			{
				selectedObject = hitObject.transform.gameObject;
			}
			else
			{
				selectedObject = null;
			}
		}

		if (selectedObject != null)
		{
			devPointer.transform.position = selectedObject.transform.position + new Vector3(0, 2f);
		}
		else
		{
			devPointer.transform.position = new Vector3(0, -5f);
		}
	}
}
